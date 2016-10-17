
int		ft_little_to_big(int little)
{
	return ((little << 24 & 0xFF000000) | (little << 8 & 0xFF0000)
				| (little >> 8 & 0xFF00) | (little >> 24 & 0xFF));
}
