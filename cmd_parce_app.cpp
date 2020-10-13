#include <stdlib.h>
#include <stdio.h>
#include <getopt.h>


int main (int argc, char *argv[]){

	bool h_used = false;
	bool l_used = false;
	bool v_used = false;
	bool V_used = false;
	bool L_used = false;

	const char* short_options = "hlL::vV::";

	const struct option long_options[] = {
		{"help",no_argument,NULL,'h'},
		{"list",optional_argument,NULL,'l'},
		{"version",no_argument,NULL,'v'},
		{"value",optional_argument,NULL,'V'},
		{NULL,0,NULL,0}
	};

	int rez;
	int option_index = -1;

	while ((rez=getopt_long(argc,argv,short_options,
		long_options,&option_index))!=-1){

		switch(rez){
			case 'h': {
				if (!h_used)
					printf("Arg: Help\n");
				h_used = true;
				break;
			};
			case 'l': {
				if (!l_used)
					if (option_index > 0)
						if (optarg != NULL)
							printf("Arg: List, Elements: %s\n", optarg);
						else
						printf("Arg: List\n");
					else
						printf("Arg: List\n");
				l_used = true;
				break;
			};
			case 'v': {
				if (!v_used)
					printf("Arg: Version\n");
				v_used = true;
				break;
			};
			case 'V': {
				if (!V_used)
					if (optarg != NULL)
						printf("Arg: Value, Val: %s\n", optarg);
					else
						printf("Arg: Value\n");
				V_used = true;
				break;
			};
			case 'L': {
				if (!L_used)
					if (optarg != NULL)
						printf("Arg: List, Elements: %s\n", optarg);
					else
						printf("Arg: List\n");
				L_used = true;
				break;
			};
			case '?': default: {
				printf("found unknown option\n");
				break;
			};
		};
		option_index = -1;
	};
	return 0;
};
