-------------------------------------------------------------------------------
-- Copyright &copy; 2015 Ben Blazak <bblazak@fullerton.edu>
-- Released under the [MIT License] (http://opensource.org/licenses/MIT)
-------------------------------------------------------------------------------

function strip_extensions(s)
  s = s:gsub( '%..*', '' )
  tex.print(s)
end

function doc_title(s)
  s = s:gsub( '%..*', '' ):gsub( '-', ' ' )
  s = s:gsub( '^%l', string.upper ):gsub( ' %l', string.upper )
  tex.print(s)
end

