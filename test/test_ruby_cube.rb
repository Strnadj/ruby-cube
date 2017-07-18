require "minitest/autorun"
require "ruby_cube"

class TestRubyCube < Minitest::Test
  def test_axes
    {
      x: %i(a b c),
      y: %i(d e f)
    }
  end

  def setup
    @cube = RubyCube.new(test_axes)
  end

  def test_invalid_initialize
    assert_raises TypeError do
      RubyCube.new(%i(arg1 arg2))
    end
  end

  def test_duplicity_key
    assert_raises TypeError do
      a = RubyCube.new({
        a: %i(a b),
        b: %i(b c)
      })
    end
  end

  def test_axe_values
    assert_equal @cube.axe_values(:x), %i(a b c)
    assert_nil @cube.axe_values(:a)
  end

  def test_fill
    ret = @cube.fill(5)
    arr = Array.new(9, 5)
    assert_equal @cube.instance_variable_get(:@data), arr
    assert_equal ret, arr
  end

  def test_proxy_get
    assert_equal @cube[:x], @cube
  end

  def test_proxy_set

  end

  def test_valid_initialize
    assert_equal @cube.instance_variable_get(:@axes), test_axes
    assert_equal @cube.dimension, 2
    assert_equal @cube.sizes, test_axes.values
    assert_equal @cube.instance_variable_get(:@max_size), 9
    assert_equal @cube.instance_variable_get(:@data).size, 9
  end
end
