require "minitest/autorun"
require "ruby_cube"

class TestRubyCube < Minitest::Test
  def test_sanity
    assert_equal "hello world", RubyCube.hello_world
  end
end
