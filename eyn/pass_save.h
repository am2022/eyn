#include <stdio.h>
#include <stdlib.h>

void pass_save_txt(char fname[30], int p1, int p2){
    int e_year;
    int e_month;
    int e_day;

    e_year = year();
    e_month = month();
    e_day = day();

	FILE *pass_save;
	pass_save = fopen(fname, "wb");

    fprintf(pass_save, "date: %d / %d / %d\n", e_month, e_day, e_year);
	fprintf(pass_save, "password1:%d\npassword2:%d", p1, p2);

	fclose(pass_save);

	printf("done!\n");
}

void pass_save_html(char fname[30], int p1, int p2){
    int e_year;
    int e_month;
    int e_day;

    e_year = year();
    e_month = month();
    e_day = day();

	FILE *pass_save;

	pass_save = fopen(fname, "wb");

	fprintf(pass_save, "<html>\n");
	fprintf(pass_save, "<head>\n");
	fprintf(pass_save, "<title>eyn passwords</title>\n");
	fprintf(pass_save, "</head>\n");
	fprintf(pass_save, "<body>\n");
	fprintf(pass_save, "<h1 style=\"text-align:center;\">eyn password</h1>");
	fprintf(pass_save, "<h1 style=\"text-align:center;\">date: %d / %d / %d</h1>", e_month, e_day, e_year);
	fprintf(pass_save, "<hr>");
	fprintf(pass_save, "<h1>password1:%d</h1>\n", p1);
	fprintf(pass_save, "<h1>password2:%d</h1>\n", p2);
	fprintf(pass_save, "</body>\n");
	fprintf(pass_save, "</html>");

	fclose(pass_save);

	printf("done!\n");
}

void pass_save_md(char fname[30], int p1, int p2){
    int e_year;
    int e_month;
    int e_day;

    e_year = year();
    e_month = month();
    e_day = day();

	FILE *pass_save;

	pass_save = fopen(fname, "wb");

    fprintf(pass_save, "## date: %d / %d / %d\n", e_month, e_day, e_year);
	fprintf(pass_save, "## password1:%d\n", p1);
	fprintf(pass_save, "## password2:%d\n", p2);

	fclose(pass_save);

	printf("done!\n");
}

void pass_save_key(char fname[30], int p1, int p2){
    FILE *pass_save;

    pass_save = fopen(fname, "wb");

    fprintf(pass_save, "%d\n", p1);
    fprintf(pass_save, "%d\n", p2);

    fclose(pass_save);

    printf("done!\n");
}

int pass_save(char *s_p1, char *s_p2){
	char pass_choice;
	char pass_file_name[30];

    int p1 = atoi(s_p1);
    int p2 = atoi(s_p2);

    printf("\n");
	printf("for save password to a file enter 1\n");
	printf("for save password as html file enter 2\n");
	printf("for save password as md file enter 3\n");
    printf("for save password as key file for importing it another time enter 4\n");
	printf("and for no option enter n\n");
	printf(":");
	scanf(" %c", &pass_choice);

	if(pass_choice == '1'){
		printf("enter the name of your password file you want to export:\n");
		scanf("%s", &pass_file_name);

		pass_save_txt(pass_file_name, p1, p2);
	}else if(pass_choice == '2'){
		printf("enter the name of your password file you want to export(.html):\n");
		scanf("%s", &pass_file_name);

		pass_save_html(pass_file_name, p1, p2);
	}else if(pass_choice == '3'){
		printf("enter the name of your password file you want to export(.md):\n");
		scanf("%s", &pass_file_name);

		pass_save_md(pass_file_name, p1, p2);
	}else if(pass_choice == '4'){
        printf("enter the name of your password file you want to export(.key):\n");
        scanf("%s", &pass_file_name);

        pass_save_key(pass_file_name, p1, p2);
    }else if(pass_choice == 'n'){
		return 0;
	}else{
		printf("invalid option, please enter again!\n");
		pass_save(s_p1, s_p2);
	}
}
