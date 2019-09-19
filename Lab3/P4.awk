BEGIN {
  count = 1
}
{
  for(i = 1; i <= NF; i++)
  {
    print $i, " -> ", count; 
  }
  count++
}
END{}