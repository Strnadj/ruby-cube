#include "ruby.h"

static VALUE hello_world(VALUE klass)
{
  return rb_str_new2("hello world");
}

void Init_ruby_cube()
{
  VALUE mRubyCube = rb_define_class("RubyCube", rb_cObject);
  rb_define_singleton_method(mRubyCube, "hello_world", hello_world, 0);
}
