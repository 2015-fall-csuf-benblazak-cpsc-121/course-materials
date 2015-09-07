-------------------------------------------------------------------------------
-- Copyright &copy; 2015 Ben Blazak <bblazak@fullerton.edu>
-- Released under the [MIT License] (http://opensource.org/licenses/MIT)
-------------------------------------------------------------------------------

function jobname_root(s)
  s = s:gsub( '^%.', '' ):gsub( '%..*', '' )
  return s
end

function doc_title(s)
  s = jobname_root(s):gsub( '-', ' ' )
  s = s:gsub( '^%l', string.upper ):gsub( ' %l', string.upper )
  return s
end

