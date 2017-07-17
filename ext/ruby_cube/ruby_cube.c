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


void Init_ruby_cube()
{
  VALUE mRubyCube = rb_define_class("RubyCube", rb_cObject);
  rb_define_method(mRubyCube, "initialize", (VALUE(*)(ANYARGS))t_init, 1);

  // Define attr acessors
  rb_define_attr(mRubyCube, "data", 1, 1);
  rb_define_attr(mRubyCube, "sizes", 1, 0);
  rb_define_attr(mRubyCube, "dimension", 1, 0);
}
