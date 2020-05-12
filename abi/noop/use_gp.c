int 
test_gp(int x)
{
  if (x) {
    return test_gp(!x);
  }
  return 0;
}

static int
no_gp(int x)
{
  if (x) {
    return no_gp(!x);
  }

  return 0;
}

