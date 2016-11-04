#include "libft.h"
#include <wchar.h>
#include <stdio.h>
#include <locale.h>

int	main()
{
	char *l = setlocale(LC_ALL, "");
	wchar_t test[] = L"🚴ﾰᏪ我漣ᡀ豈༕aéééڰÃ";
//	wchar_t test[] = L"α";

	ft_putwchar(test);
	/*
	ft_putnbr(sizeof(test));
	ft_putchar('\n');

	//wprintf(L"test : %ls\n", test);
//	wprintf(L"test : %ls\n", L"éééڰ");
	ft_putwchar(test);
	*/
	return (0);
}
