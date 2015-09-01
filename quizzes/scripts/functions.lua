-------------------------------------------------------------------------------
-- Copyright &copy; 2015 Ben Blazak <bblazak@fullerton.edu>
-- Released under the [MIT License] (http://opensource.org/licenses/MIT)
-------------------------------------------------------------------------------

function doc_name(s)
  s = s:gsub( '(%a+-%d+).*', '%1' )
  tex.print(s)
end

function doc_title(s)
  s = s:gsub( '(%a)(%a+)-(%d+).*', '%1%2 %3' ):gsub( '^%l', string.upper )
  tex.print(s)
end

