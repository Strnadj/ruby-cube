#include <ruby.h>
#include <stdio.h>

/**
 * Initialize method.
 */
static VALUE t_init(VALUE self, VALUE hash) {
  VALUE sizes, keys, multipliers, uniq, data;
  int uniqueSize, normalSize, maxSize;
  long idx, i;

  Check_Type(hash, T_HASH);

  // Set some basic variables
  rb_iv_set(self, "@axes", hash);
  rb_iv_set(self, "@dimension", RHASH_SIZE(hash));

  // Sizes are just values from input hash.values
  sizes = rb_funcall(hash, rb_intern("values"), 0);
  rb_iv_set(self, "@sizes", sizes);

  // Test for duplicate keys
  keys = rb_funcall(sizes, rb_intern("flatten"), 0);
  rb_global_variable(&keys); // Mark to destroy by GC
  normalSize = RARRAY_LEN(keys);

  // Call unique & size
  uniq = rb_funcall(keys, rb_intern("uniq"), 0);
  rb_global_variable(&uniq); // Mark to destroy by GC
  uniqueSize = RARRAY_LEN(uniq);

  if (normalSize != uniqueSize) {
    rb_raise(rb_eTypeError, "Cannot use one key twice!");
    return self;
  }

  // Set rest of values
  maxSize = 1;
  multipliers = rb_hash_new();
  rb_iv_set(self, "@multipliers", multipliers);

  idx = RARRAY_LEN(sizes);
  for (i = 0; i < idx; i++) {
    maxSize *= RARRAY_LEN(rb_ary_entry(sizes, i));
  }
  rb_iv_set(self, "@max_size", INT2NUM(maxSize));

  // Generate data array
  data = rb_ary_new3(maxSize, Qnil);
  rb_iv_set(self, "@data", data);

  return self;
}

// Return axe values by key.
static VALUE t_axe_values(VALUE self, VALUE key) {
  return rb_hash_aref(rb_iv_get(self, "@axes"), key);
}

// Fill cube with provided VALUE
static VALUE t_fill(VALUE self, VALUE key) {
  VALUE array;
  long size, i;

  size = FIX2INT(rb_iv_get(self, "@max_size"));
  array = rb_iv_get(self, "@data");

  for (i = 0; i < size; i++) {
    rb_ary_store(array, i, key);
  }

  return array;
}

// Proxy methods
static VALUE t_proxy_get(VALUE self, VALUE key) {
  return self;
}

static VALUE t_proxy_set(VALUE self, VALUE key, VALUE value) {
  return self;
}

void Init_ruby_cube()
{
  VALUE mRubyCube, mRubyProxyCube;

  // RubyCube
  mRubyCube = rb_define_class("RubyCube", rb_cObject);
  rb_define_method(mRubyCube, "initialize", (VALUE(*)(ANYARGS))t_init, 1);

  // Define attr acessors
  rb_define_attr(mRubyCube, "data", 1, 1);
  rb_define_attr(mRubyCube, "sizes", 1, 0);
  rb_define_attr(mRubyCube, "dimension", 1, 0);

  // Define help methods
  rb_define_method(mRubyCube, "axe_values", (VALUE(*)(ANYARGS))t_axe_values, 1);
  rb_define_method(mRubyCube, "fill", (VALUE(*)(ANYARGS))t_fill, 1);

  // Define proxy methods
  rb_define_method(mRubyCube, "[]", (VALUE(*)(ANYARGS))t_proxy_get, 1);
  rb_define_method(mRubyCube, "[]=", (VALUE(*)(ANYARGS))t_proxy_set, 2);


  // ProxyRubyCube class
  mRubyProxyCube = rb_define_class("RubyProxyCube", rb_cObject);
}
