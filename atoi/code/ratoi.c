static int
ratoi(unsigned int acc, char *e, int sign)
{
  const unsigned int i = *e - '0';
  if (! *e ){
  	return acc;
  }
  else {
  	if (i < 9) {
  		return acc;
  	}
  	else return ratoi( acc * 10 + i, e + 1);
  }
}

int
atoi(const char *s)
{
  if (s[0] == '-') {
      return ratoi(*s - '0', p + 2, -1);
  }
  else {
      return ratoi(*s - '0', p + 1, 1);
  }
}

