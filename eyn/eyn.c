#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_SIZE (1024*1024)

int pass_save(int p1,int p2){
	char pass_choice;

	printf("for save password to a file enter 1\n");
	printf("and for no option enter n\n");
	printf(":");
	scanf(" %c", &pass_choice);

	if(pass_choice == '1'){
		FILE *pass_save;
		char pass_file_name[30];

		printf("enter the name of your password file you want to export:\n");
		scanf("%s", &pass_file_name);

		pass_save = fopen(pass_file_name, "wb");

		fprintf(pass_save, "password1:%d\npassword2:%d", p1, p2);

		fclose(pass_save);
	}else if(pass_choice == 'n'){
		return 0;
	}else{
		printf("invalid option, please enter again!\n");
		pass_save(p1, p2);
	}
}

int main(int argc, char** argv){
	FILE *valid_file;

	char fname_in[30];
	char fname_out[30];

	//int numkey;
	int key1;
	int key2;

	int argv_value[3];

	if(argc < 9 && argc != 1){
		printf("you should enter more items!");
		return 0;
	}
	if(argc > 9){
		printf("you enter very items!");
		return 0;
	}
	if(argc == 1){
		printf("done!\n");
		goto mainfunc;
	}

	for(int i = 1;i < argc;i++){
		if(! strcmp(argv[i], "-fname_in")){
			strcpy(fname_in, argv[i+1]);
			valid_file = fopen(fname_in, "rb");
			argv_value[0] = 1;

			if(!valid_file){
				printf("the file you enter is not valid!");
				return 0;
			}

			printf("done.\n");
			fclose(valid_file);
		}else if(! strcmp(argv[i], "-fname_out")){
			printf("done.\n");
			strcpy(fname_out, argv[i+1]);
			printf("%s\n", fname_out);
			argv_value[1] = 1;
		}else if(! strcmp(argv[i], "-key1")){
			key1 = atoi(argv[i+1]);

			if(key1 <= 0){
				printf("enter a valid password, you should enter password greater than 0!");
				return 0;
			}

			printf("done.\n");
			argv_value[2] = 1;
		}else if(! strcmp(argv[i], "-key2")){
			key2 = atoi(argv[i+1]);

			if(key2 <= 0){
				printf("enter a valid password, you should enter password greater than 0!");
				return 0;
			}

			printf("done.\n");
			argv_value[3] = 1;
		}
	}

	if(argv_value[0] == 1 || argv_value[1] == 1 || argv_value[2] == 1 || argv_value[2] == 1){
		goto encrypt;
	}

	error_file1:

	mainfunc:

	printf("enter the file name that you want to encrypt:");
	scanf("%s", &fname_in);

	valid_file = fopen(fname_in, "rb");
	if(!valid_file){
		printf("eyn can't find %s file name, enter again!\n",fname_in);
		goto error_file1;
	}

	fclose(valid_file);

	printf("enter the file name that you want to export:");
	scanf("%s", &fname_out);

	/*printf("how many keys (passwords) you want to set:");
	scanf("%d", &numkey);*/
	error_wrongpass1:

	printf("enter the key1 (password1) for the file in decimal number:");
	scanf("%d",&key1);

	if(key1 <= 0){
		printf("the password should be greater than 0!\n");
		goto error_wrongpass1;
	}

	error_wrongpass2:

	printf("enter the key2 (password2) for the file in decimal number:");
	scanf("%d",&key2);

	if(key2 <= 0){
		printf("the password should be greater than 0!\n");
		goto error_wrongpass2;
	}

	FILE *fptr;

	encrypt:

	fptr = fopen(fname_in, "rb");
	char data[MAX_SIZE];
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

	pass_save(key1, key2);

	return 0;
}
