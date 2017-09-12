extern unsigned int length(const char *s);

extern unsigned int get_digit(char c);

extern int isdigit(char c);

static int ps[] = {1, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000};

int
simple_atoi(const char *a)
{

  int num = 0;
  unsigned int start;
	int i, pow;
	unsigned int digit;
  
  const unsigned int len = length(a);
	pow = 0;

	int first = isdigit(a[0]) ? 0 : 1;
	
	for (i = len - 1; i >= first; i --)
	{
	  digit = get_digit(a[i]);

		num += digit * ps[pow ++];
	}

  if (a[0] == '-') return -1 * num;
  else return num;
}
