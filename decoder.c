#include "decoder.h"

void decodeInstruction(instruction_t instruction, uint32_t *registros, char *flag, uint32_t *PC)
{
    // instruction.op1_value --> Valor primer operando
    // instruction.op1_type  --> Tipo primer operando (R->Registro #->Numero N->Ninguno)
    // ... Igual para los otros operandos
	if(strcmp(instruction.mnemonic,"ADD")==0)
    {
        if((instruction.op3_type=='N')||(instruction.op2_type=='R'))
        {
            ADD(&registros[instruction.op1_value],registros[instruction.op1_value],registros[instruction.op2_value],flag);
            *PC++;
        }
        if((instruction.op3_type=='N')||(instruction.op2_type=='#'))
        {
            ADD(&registros[instruction.op1_value],registros[instruction.op1_value],instruction.op2_value,flag);
        }
        if(instruction.op3_type=='R')
        {
            ADD(&registros[instruction.op1_value],registros[instruction.op2_value],registros[instruction.op3_value],flag);
        }
        if(instruction.op3_type=='#')
        {
            ADD(&registros[instruction.op1_value],registros[instruction.op2_value],instruction.op3_value,flag);
        }
    }
    if(strcmp(instruction.mnemonic,"AND")==0)
    {
        if((instruction.op3_type=='N')||(instruction.op2_type=='R'))
        {
            AND(&registros[instruction.op1_value],registros[instruction.op1_value],registros[instruction.op2_value],flag);
        }
        if((instruction.op3_type=='N')||(instruction.op2_type=='#'))
        {
            AND(&registros[instruction.op1_value],registros[instruction.op1_value],instruction.op2_value,flag);
        }
        if(instruction.op3_type=='R')
        {
            AND(&registros[instruction.op1_value],registros[instruction.op2_value],registros[instruction.op3_value],flag);
        }
        if(instruction.op3_type=='#')
        {
            AND(&registros[instruction.op1_value],registros[instruction.op2_value],instruction.op3_value,flag);
        }
    }
    if(strcmp(instruction.mnemonic,"EOR")==0)
    {
        if((instruction.op3_type=='N')||(instruction.op2_type=='R'))
        {
            EOR(&registros[instruction.op1_value],registros[instruction.op1_value],registros[instruction.op2_value],flag);
        }
        if((instruction.op3_type=='N')||(instruction.op2_type=='#'))
        {
            EOR(&registros[instruction.op1_value],registros[instruction.op1_value],instruction.op2_value,flag);
        }
        if(instruction.op3_type=='R')
        {
            EOR(&registros[instruction.op1_value],registros[instruction.op2_value],registros[instruction.op3_value],flag);
        }
        if(instruction.op3_type=='#')
        {
            EOR(&registros[instruction.op1_value],registros[instruction.op2_value],instruction.op3_value,flag);
        }
    }
    if(strcmp(instruction.mnemonic,"MOV")==0)
    {
        if(instruction.op2_type=='R')
        {
            MOV(&registros[instruction.op1_value],registros[instruction.op2_value],flag);
        }
        if(instruction.op2_type=='#')
        {
            MOV(&registros[instruction.op1_value],instruction.op2_value,flag);
        }
    }
    if(strcmp(instruction.mnemonic,"ORR")==0)
    {
        if((instruction.op3_type=='N')||(instruction.op2_type=='R'))
        {
            ORR(&registros[instruction.op1_value],registros[instruction.op1_value],registros[instruction.op2_value],flag);
        }
        if((instruction.op3_type=='N')||(instruction.op2_type=='#'))
        {
            ORR(&registros[instruction.op1_value],registros[instruction.op1_value],instruction.op2_value,flag);
        }
        if(instruction.op3_type=='R')
        {
            ORR(&registros[instruction.op1_value],registros[instruction.op2_value],registros[instruction.op3_value],flag);
        }
        if(instruction.op3_type=='#')
        {
            ORR(&registros[instruction.op1_value],registros[instruction.op2_value],instruction.op3_value,flag);
        }
    }
    if(strcmp(instruction.mnemonic,"SUB")==0)
    {
        if((instruction.op3_type=='N')||(instruction.op2_type=='R'))
        {
            SUB(&registros[instruction.op1_value],registros[instruction.op1_value],registros[instruction.op2_value],flag);
        }
        if((instruction.op3_type=='N')||(instruction.op2_type=='#'))
        {
            SUB(&registros[instruction.op1_value],registros[instruction.op1_value],instruction.op2_value,flag);
        }
        if(instruction.op3_type=='R')
        {
            SUB(&registros[instruction.op1_value],registros[instruction.op2_value],registros[instruction.op3_value],flag);
        }
        if(instruction.op3_type=='#')
        {
            SUB(&registros[instruction.op1_value],registros[instruction.op2_value],instruction.op3_value,flag);
        }
    }
    if(strcmp(instruction.mnemonic,"LSLS")==0)
    {
        if(instruction.op2_type=='R')
        {
            LSLS(&registros[instruction.op1_value],registros[instruction.op2_value],flag);
        }
        if(instruction.op2_type=='#')
        {
            LSLS(&registros[instruction.op1_value],instruction.op2_value,flag);
        }
    }
    if(strcmp(instruction.mnemonic,"LSRS")==0)
    {
        if(instruction.op2_type=='R')
        {
            LSRS(&registros[instruction.op1_value],registros[instruction.op2_value],flag);
        }
        if(instruction.op2_type=='#')
        {
            LSRS(&registros[instruction.op1_value],instruction.op2_value,flag);
        }
    }
    if(strcmp(instruction.mnemonic,"RORS")==0)
    {
        if(instruction.op2_type=='R')
        {
            RORS(&registros[instruction.op1_value],registros[instruction.op2_value],flag);
        }
        if(instruction.op2_type=='#')
        {
            RORS(&registros[instruction.op1_value],instruction.op2_value,flag);
        }
    }
    if(strcmp(instruction.mnemonic,"BICS")==0)
    {
        if(instruction.op2_type=='R')
        {
            BICS(&registros[instruction.op1_value],registros[instruction.op2_value],flag);
        }
        if(instruction.op2_type=='#')
        {
            BICS(&registros[instruction.op1_value],instruction.op2_value,flag);
        }
    }
    if(strcmp(instruction.mnemonic,"NOP")==0)
    {

    }
    if(strcmp(instruction.mnemonic,"MVNS")==0)
    {
        if(instruction.op2_type=='R')
        {
            MVNS(&registros[instruction.op1_value],registros[instruction.op2_value],flag);
        }
        if(instruction.op2_type=='#')
        {
            MVNS(&registros[instruction.op1_value],instruction.op2_value,flag);
        }
    }
    if(strcmp(instruction.mnemonic,"CMN")==0)
    {
        if((instruction.op1_type=='R')||(instruction.op2_type=='R'))
        {
            CMN(registros[instruction.op1_value],registros[instruction.op2_value],flag);
        }
        if((instruction.op1_type=='R')||(instruction.op2_type=='#'))
        {
            CMN(registros[instruction.op1_value],instruction.op2_value,flag);
        }
        if((instruction.op1_type=='#')||(instruction.op2_type=='R'))
        {
            CMN(instruction.op1_value,registros[instruction.op2_value],flag);
        }
        if((instruction.op1_type=='#')||(instruction.op2_type=='#'))
        {
            CMN(instruction.op1_value,instruction.op2_value,flag);
        }
    }
    if(strcmp(instruction.mnemonic,"CMP")==0)
    {
        if((instruction.op1_type=='R')||(instruction.op2_type=='R'))
        {
            CMP(registros[instruction.op1_value],registros[instruction.op2_value],flag);
        }
        if((instruction.op1_type=='R')||(instruction.op2_type=='#'))
        {
            CMP(registros[instruction.op1_value],instruction.op2_value,flag);
        }
        if((instruction.op1_type=='#')||(instruction.op2_type=='R'))
        {
            CMP(instruction.op1_value,registros[instruction.op2_value],flag);
        }
        if((instruction.op1_type=='#')||(instruction.op2_type=='#'))
        {
            CMP(instruction.op1_value,instruction.op2_value,flag);
        }
    }
    if(strcmp(instruction.mnemonic,"RSBS")==0)
    {
        if(instruction.op2_type=='R')
        {
            RSBS(&registros[instruction.op1_value],registros[instruction.op2_value],flag);
        }
        if(instruction.op2_type=='#')
        {
            RSBS(&registros[instruction.op1_value],instruction.op2_value,flag);
        }
    }
    if(strcmp(instruction.mnemonic,"REV")==0)
    {
        if(instruction.op2_type=='N')
        {
            REV(&registros[instruction.op1_value],registros[instruction.op1_value]);
        }
        else
        {
            REV(&registros[instruction.op1_value],registros[instruction.op2_value]);
        }
    }
    if(strcmp(instruction.mnemonic,"REV16")==0)
    {
        if(instruction.op2_type=='N')
        {
            REV16(&registros[instruction.op1_value],registros[instruction.op1_value]);
        }
        else
        {
            REV16(&registros[instruction.op1_value],registros[instruction.op2_value]);
        }
    }
    if(strcmp(instruction.mnemonic,"REVSH")==0)
    {
        if(instruction.op2_type=='N')
        {
            REVSH(&registros[instruction.op1_value],registros[instruction.op1_value]);
        }
        else
        {
            REVSH(&registros[instruction.op1_value],registros[instruction.op2_value]);
        }
    }
    if(strcmp(instruction.mnemonic,"TST")==0)
    {
        if(instruction.op2_type=='N')
        {
            TST(&registros[instruction.op1_value],registros[instruction.op1_value]);
        }
        else
        {
            TST(&registros[instruction.op1_value],registros[instruction.op2_value]);
        }
    }
}
instruction_t getInstruction(char* instStr)
{
	instruction_t instruction;
	char* split = (char*)malloc(strlen(instStr)+1);
	int num=0;

	strcpy(split, instStr);
	/* Obtiene el mnemonico de la instrucción */
	split = strtok(split, " ,");
	strcpy(instruction.mnemonic, split);

	/* Separa los operandos */
	while (split != NULL)
	{
		switch(num){
			case 1:
				instruction.op1_type  = split[0];
				instruction.op1_value = (uint32_t)strtoll(split+1, NULL, 0);
				break;

			case 2:
				instruction.op2_type  = split[0];
				instruction.op2_value = (uint32_t)strtoll(split+1, NULL, 0);
				break;

			case 3:
				instruction.op3_type  = split[0];
				instruction.op3_value = (uint32_t)strtoll(split+1, NULL, 0);
				break;
		}

		split = strtok(NULL, " ,.");
		num++;
	}

	if(num==3){
		instruction.op3_type  = 'N';
		instruction.op3_value = 0;
	}

	free(split);

	return instruction;
}

int readFile(char* filename, ins_t* instructions)
{
	FILE* fp;	/* Puntero a un archivo  */
	int lines;	/* Cantidad de líneas del archivo */
	int line=0;	/* Línea leida */
	char buffer[50]; /* Almacena la cadena leida */

	fp = fopen(filename, "r");	/* Abrir el archivo como solo lectura */
	if( fp==NULL )
		return -1;	/* Error al abrir el archivo */

	lines = countLines(fp);	/* Cantidad de líneas*/

	/* Asignación dinámica de memoria para cada instrucción */
	instructions->array = (char**)malloc(lines*sizeof(char*));
	while ( fgets(buffer, 50, fp) != NULL && line<lines ){
        instructions->array[line] = (char*)malloc((strlen(buffer)+1)*sizeof(char));
		strcpy(instructions->array[line], buffer);
		line++;
 	}

	fclose(fp);	/* Cierra el archivo */

	return lines;
}


int countLines(FILE* fp)
{
	int lines=0;
	char buffer[50];

	while( fgets(buffer, 50, fp) != NULL )
		lines++;

	rewind(fp);

	return lines;
}

