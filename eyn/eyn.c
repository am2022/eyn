#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include "eyn_time.h"
#include "help.h"
#include "eyn_color.h"
#include "pass_save.h"

#define MAX_SIZE (1024*1024*5)

#if defined(_WIN32)
    #define PLATFORM "win"
#elif defined(__linux__)
	#define PLATFORM "linux"
#else
	#define PLATFORM "unix"
#endif

int main(int argc, char** argv){
	FILE *valid_file;

	char fname_in[30];
	char fname_out[30];

	//int numkey;
	int key1;
	int key2;

    char s_key1[30];
    char s_key2[30];

    char s_import_pass[30];
    char import_pass_choice[5];
    char import_file_name[30];

    int import_pass;

	int argv_value[3];

    char txt_out[30];
    char md_out[30];
    char html_out[30];

    int e_year;
    int e_month;
    int e_day;

    char pass_name_key[30];

    e_year = year();
    e_month = month();
    e_day = day();

	if(argc < 2 && argc != 1){
		printf("you should enter more items!");
		return 0;
	}
	if(argc > 15){
		printf("you enter very items!");
		return 0;
	}
	if(argc == 1){
		goto mainfunc;
	}

	for(int i = 1;i < argc;i++){
		if(! strcmp(argv[i], "-fname_in") || ! strcmp(argv[i], "-i")){
			strcpy(fname_in, argv[i+1]);
			valid_file = fopen(fname_in, "rb");
			argv_value[0] = 1;

			if(!valid_file){
				printf("the file you enter is not valid!");
				return 0;
			}

			printf("done.\n");
			fclose(valid_file);
		}else if(! strcmp(argv[i], "-fname_out") || ! strcmp(argv[i], "-o")){
			printf("done.\n");
			strcpy(fname_out, argv[i+1]);
			printf("%s\n", fname_out);
			argv_value[1] = 1;
		}else if(! strcmp(argv[i], "-key1") || ! strcmp(argv[i], "-k1")){
			key1 = atoi(argv[i+1]);

			if(key1 <= 0){
				printf("enter a valid password, you should enter password greater than 0!");
				return 0;
			}

			printf("done.\n");
			argv_value[2] = 1;
		}else if(! strcmp(argv[i], "-key2") || ! strcmp(argv[i], "-k2")){
			key2 = atoi(argv[i+1]);

			if(key2 <= 0){
				printf("enter a valid password, you should enter password greater than 0!");
				return 0;
			}

			printf("done.\n");
			argv_value[3] = 1;
		}else if(! strcmp(argv[i], "-txt_o")){
            strcpy(txt_out, argv[i+1]);

            pass_save_txt(txt_out, key1, key2);
        }else if(! strcmp(argv[i], "-md_o")){
            strcpy(md_out, argv[i+1]);

            pass_save_md(md_out, key1, key2);
        }else if(! strcmp(argv[i], "-html_o")){
            strcpy(html_out, argv[i+1]);

            pass_save_html(html_out, key1, key2);
        }else if(! strcmp(argv[i], "--help") || ! strcmp(argv[i], "-help") || ! strcmp(argv[i], "-h")){
            argv_help();
            return 0;
        }else if(! strcmp(argv[i], "-key") || ! strcmp(argv[i], "-k")){
            strcpy(pass_name_key, argv[i+1]);

            pass_save_key(pass_name_key, key1, key2);
        }else if(! strcmp(argv[i], "-imp")){
            char imp_fname[30];

            char s_imp_key1[30];
            char s_imp_key2[30];

            strcpy(imp_fname, argv[i+1]);

            FILE *imp;
            imp = fopen(imp_fname, "rb");

            if(!imp){
                printf("the file is invalid!");
                return 0;
            }

            fscanf(imp, "%s\n", s_imp_key1);
            fscanf(imp, "%s", s_imp_key2);

            key1 = atoi(s_imp_key1);
            key2 = atoi(s_imp_key2);

            fclose(imp);

            goto encrypt;
        }
	}

	if(argv_value[0] == 1 || argv_value[1] == 1 || argv_value[2] == 1 || argv_value[2] == 1){
		goto encrypt;
	}

	error_file1:

	mainfunc:

    if(! strcmp(PLATFORM, "win")){
        system("cls");
    }else if(! strcmp(PLATFORM, "linux") || ! strcmp(PLATFORM, "unix")){
        system("clear");
    }else{
        system("clear");
    }

    printf("date: %d / %d / %d\n", e_month, e_day, e_year);

	printf("enter -q for exit || enter -clear for clear the screen || -color for change color\n");
	printf("enter the file name that you want to encrypt:");
	scanf("%s", &fname_in);

	if(! strcmp(fname_in, "-q")){
		return 0;
	}else if(! strcmp(fname_in, "-clear")){
        if(! strcmp(PLATFORM, "win")){
    		system("cls");
    		goto mainfunc;
    	}else if(! strcmp(PLATFORM, "linux") || ! strcmp(PLATFORM, "unix")){
    		system("clear");
    		goto mainfunc;
    	}
    }else if(! strcmp(fname_in, "-color")){
        if(! strcmp(PLATFORM, "win")){
            main_color("win");
            system("cls");
            goto mainfunc;
        }else if(! strcmp(PLATFORM, "linux") || ! strcmp(PLATFORM, "unix")){
            printf("we don't have this option for linux and osx for now");
            system("clear");
            goto mainfunc;
        }else{
            printf("your os was not detected!");
            system("clear");
            goto mainfunc;
        }
    }

	valid_file = fopen(fname_in, "rb");
	if(!valid_file){
		printf("eyn can't find %s file name, enter again!\n",fname_in);
		goto error_file1;
	}

	fclose(valid_file);

    export:

	printf("enter -q for exit || enter -clear for clear the screen\n");
	printf("enter the file name that you want to export:");
	scanf("%s", &fname_out);

	if(! strcmp(fname_out, "-q")){
		return 0;
	}else if(! strcmp(fname_out, "-clear")){
        if(! strcmp(PLATFORM, "win")){
    		system("cls");
            goto export;
    	}else if(! strcmp(PLATFORM, "linux") || ! strcmp(PLATFORM, "unix")){
    		system("clear");
            goto export;
    	}
    }

    error_import_pass:

    printf("did you want to import your password in .key format(y/n):");
    scanf("%s", &import_pass_choice);

    if(! strcmp(import_pass_choice, "yes") || import_pass_choice[0] == 'y'){
        FILE *import;

        printf("enter password file you want to import:");
        scanf("%s", &import_file_name);

        import = fopen(import_file_name, "rb");

        if(!import){
            printf("the file is not valid!\n");
            goto error_import_pass;
        }

        fscanf(import, "%s\n", s_key1);
        fscanf(import, "%s", s_key2);

        key1 = atoi(s_key1);
        key2 = atoi(s_key2);

        fclose(import);

        goto encrypt;
    }

	/*printf("how many keys (passwords) you want to set:");
	scanf("%d", &numkey);*/
	error_wrongpass1:

	printf("enter 00 for exit.\n");
	printf("enter the key1 (password1) for the file in decimal number:");
    scanf("%s", &s_key1);

	if(! strcmp(s_key1, "00")){
		return 0;
	}

    key1 = atoi(s_key1);

	if(key1 <= 0){
		printf("the password should be greater than 0!\n");
		goto error_wrongpass1;
	}

	error_wrongpass2:

	printf("enter 00 for exit.\n");
	printf("enter the key2 (password2) for the file in decimal number:");
    scanf("%s", &s_key2);

	if(! strcmp(s_key2, "00")){
		return 0;
	}

    key2 = atoi(s_key2);

	if(key2 <= 0){
		printf("the password should be greater than 0!\n");
		goto error_wrongpass2;
	}

	FILE *fptr;

	encrypt:

	fptr = fopen(fname_in, "rb");
    char *data;
    data = malloc(MAX_SIZE);
	int i = 0;

	while(!feof(fptr)){
		if(i == MAX_SIZE){
			printf("eyn can't open this file, the file is so big!");
		}
		data[i++] = fgetc(fptr);
	}

	fclose(fptr);
	fptr = fopen(fname_out, "wb");

	for(int j = 0;j < i-1;j++){
		fputc(data[j]^key1^key2, fptr);
	}

	fclose(fptr);

    free(data);

    if(argv_value[0] == 1 || argv_value[1] == 1 || argv_value[2] == 1 || argv_value[2] == 1){
		return 0;
	}

    pass_save(s_key1, s_key2);

	char menu[4];

	error_menu:

	printf("enter no for exit or enter yes to return to the eyn:");
	scanf("%s", &menu);

	if(! strcmp(menu, "yes") || ! strcmp(menu, "y") || ! strcmp(menu, "Y")){
		goto mainfunc;
	}else if(! strcmp(menu, "no") || ! strcmp(menu, "n") || ! strcmp(menu, "N")){
		return 0;
	}else{
		printf("invalid option, enter again!\n");
        printf("enter a key for continue\n");
        getch();
		goto error_menu;
	}
	return 0;
}
