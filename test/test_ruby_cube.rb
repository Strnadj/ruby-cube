require "minitest/autorun"
require "ruby_cube"

class TestRubyCube < Minitest::Test
  def test_axes
    @test_axes ||= {
      x: %i(a b c),
      y: %i(d e f)
    }
  end

  def test_cube
    @cube ||= RubyCube.new(test_axes)
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

      puts a.instance_variable_get(:@sizes).inspect
      puts a.instance_variable_get(:@keys).inspect
      puts a.instance_variable_get(:@test).inspect
    end
  end

  def test_valid_initialize
    assert_equal test_cube.instance_variable_get(:@axes), test_axes
    assert_equal test_cube.dimension, 2
    assert_equal test_cube.sizes, test_axes.values
  end
end
