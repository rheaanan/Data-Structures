 #include <locale.h>
 #include <stdio.h>
 #include <wchar.h>
 
 
 int main() {
         wchar_t test[] = L"ಎಲ್ಲಿ";
	scanf("%ls",test);
         setlocale(LC_ALL, "");
		setbuf(stdout, NULL);
        printf("hjgh%ls\n", test);
 }
