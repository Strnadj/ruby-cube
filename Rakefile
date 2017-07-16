# -*- ruby -*-
require "rubygems"
require "hoe"

Hoe.plugin :compiler
# Hoe.plugin :gem_prelude_sucks
# Hoe.plugin :inline
Hoe.plugin :minitest
# Hoe.plugin :racc
# Hoe.plugin :rcov
# Hoe.plugin :rdoc

Hoe.spec "ruby_cube" do
  # HEY! If you fill these out in ~/.hoe_template/default/Rakefile.erb then
  # you'll never have to touch them again!
  # (delete this comment too, of course)

  developer("Strnadj", "jan.strnadek@gmail.com")
  license "MIT"

  extension 'ruby_cube'
end

Rake::Task[:test].prerequisites << :compile

# vim: syntax=ruby
