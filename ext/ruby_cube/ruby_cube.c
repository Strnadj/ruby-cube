#include <ruby.h>

/**
 * Initialize method.
 */
static VALUE t_init(VALUE self, VALUE hash) {
  Check_Type(hash, T_HASH);

  // Set some basic variables
  rb_iv_set(self, "@axes", hash);
  rb_iv_set(self, "@dimension", RHASH_SIZE(hash));

  // Sizes are just values from input hash.values
  VALUE sizes = rb_funcall(hash, rb_intern("values"), 0);
  VALUE keys  = rb_funcall(sizes, rb_intern("flatten"), 0);
  rb_iv_set(self, "@sizes", sizes);

  // Test for duplicate keys
  rb_iv_set(self, "@keys", keys);
  rb_iv_set(self, "@test", RARRAY_LEN(rb_iv_get(self, "@keys")));
  // int normalSize = FIX2INT(RARRAY_LEN(sizes));
  // int uniqueSize = FIX2INT(RARRAY_LEN(rb_funcall(sizes, rb_intern("uniq"), 0)));

  //rb_iv_set(self, "@normal", sizes);
  //rb_iv_set(self, "@uniq", rb_funcall(sizes, rb_intern("uniq"), 0));

 //if (normalSize != uniqueSize) {
 //  rb_raise(rb_eTypeError, "Cannot use one key twice!");
 //  return self;
 //}



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
