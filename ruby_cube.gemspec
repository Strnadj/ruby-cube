# -*- encoding: utf-8 -*-
# stub: ruby_cube 1.0.0.20170716203414 ruby lib
# stub: ext/ruby_cube/extconf.rb

Gem::Specification.new do |s|
  s.name = "ruby_cube"
  s.version = "1.0.0.20170716203414"

  s.required_rubygems_version = Gem::Requirement.new(">= 0") if s.respond_to? :required_rubygems_version=
  s.require_paths = ["lib"]
  s.authors = ["Strnadj"]
  s.date = "2017-07-16"
  s.description = "FIX (describe your package)"
  s.email = ["jan.strnadek@gmail.com"]
  s.executables = ["ruby_cube"]
  s.extensions = ["ext/ruby_cube/extconf.rb"]
  s.extra_rdoc_files = ["History.txt", "Manifest.txt", "README.txt"]
  s.files = [".autotest", "History.txt", "Manifest.txt", "README.txt", "Rakefile", "bin/ruby_cube", "ext/ruby_cube/extconf.rb", "lib/ruby_cube.rb", "test/test_ruby_cube.rb"]
  s.homepage = "FIX (url)"
  s.licenses = ["MIT"]
  s.rdoc_options = ["--main", "README.txt"]
  s.rubygems_version = "2.5.1"
  s.summary = "FIX (describe your package)"

  if s.respond_to? :specification_version then
    s.specification_version = 4

    if Gem::Version.new(Gem::VERSION) >= Gem::Version.new('1.2.0') then
      s.add_development_dependency(%q<minitest>, ["~> 5.10"])
      s.add_development_dependency(%q<rdoc>, ["~> 4.0"])
      s.add_development_dependency(%q<rake-compiler>, ["~> 1.0"])
      s.add_development_dependency(%q<hoe>, ["~> 3.16"])
    else
      s.add_dependency(%q<minitest>, ["~> 5.10"])
      s.add_dependency(%q<rdoc>, ["~> 4.0"])
      s.add_dependency(%q<rake-compiler>, ["~> 1.0"])
      s.add_dependency(%q<hoe>, ["~> 3.16"])
    end
  else
    s.add_dependency(%q<minitest>, ["~> 5.10"])
    s.add_dependency(%q<rdoc>, ["~> 4.0"])
    s.add_dependency(%q<rake-compiler>, ["~> 1.0"])
    s.add_dependency(%q<hoe>, ["~> 3.16"])
  end
end
