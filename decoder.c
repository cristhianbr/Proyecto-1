#include "decoder.h"

void decodeInstruction(instruction_t instruction, uint32_t *registros, char *flag, uint8_t *MemRAM, uint16_t *Mnem)
{
    // instruction.op1_value --> Valor primer operando
    // instruction.op1_type  --> Tipo primer operando (R->Registro #->Numero N->Ninguno)
    // ... Igual para los otros operandos
	uint32_t imm32;
	if(strcmp(instruction.mnemonic,"ADDS")==0)   //Si la intruccion es ADD :
    {
        if((instruction.op3_type=='N')&&(instruction.op2_type=='R')) // Si en el operando 3 no tengo nada y el operando 2 es un reguistro
        {
            registros[15]+=1;
            *Mnem=(68<<8)|((instruction.op1_value&0x07)|(instruction.op1_value&0x08)<<7)|(instruction.op2_value)<<3;
            ADDS(&registros[instruction.op1_value],registros[instruction.op1_value],registros[instruction.op2_value],flag);
        }
        if((instruction.op3_type=='N')&&(instruction.op2_type=='#')) // Si en el operando 3 no hay nada y el operando 2 es un inmediato
        {
            registros[15]+=1;
            *Mnem=(6<<11)|(instruction.op1_value<<8)|(instruction.op2_value);
            ADDS(&registros[instruction.op1_value],registros[instruction.op1_value],instruction.op2_value,flag);
        }
        if(instruction.op3_type=='R') // Si el operando 3 es un registro
        {
            registros[15]+=1;
            *Mnem=(12<<9)|(instruction.op1_value)|(instruction.op2_value<<6)|(instruction.op3_value<<3);
            ADDS(&registros[instruction.op1_value],registros[instruction.op2_value],registros[instruction.op3_value],flag);
        }
        if(instruction.op3_type=='#')//Si el operando 3 es un inmediato
        {
            registros[15]+=1;
            ADDS(&registros[instruction.op1_value],registros[instruction.op2_value],instruction.op3_value,flag);
        }
    }
        /*
        **********************************************************************************************
        *  Para la comparacion de los demas mnemonicos, se evaluan las mismas condiciones que en ADD *
        **********************************************************************************************
        */
    if(strcmp(instruction.mnemonic,"ADCS")==0) //Si la intruccion es ADCS :
    {
        if((instruction.op3_type=='N')&&(instruction.op2_type=='R')) // Si en el operando 3 no tengo nada y el operando 2 es un reguistro
        {
            registros[15]+=1;
            *Mnem=(261<<6)|(instruction.op1_value)|(instruction.op2_value<<3);
            ADCS(&registros[instruction.op1_value],registros[instruction.op1_value],registros[instruction.op2_value],flag);
        }
        if((instruction.op3_type=='N')&&(instruction.op2_type=='#')) // Si en el operando 3 no hay nada y el operando 2 es un inmediato
        {
            registros[15]+=1;
            ADCS(&registros[instruction.op1_value],registros[instruction.op1_value],instruction.op2_value,flag);
        }
        if(instruction.op3_type=='R') // Si el operando 3 es un registro
        {
            registros[15]+=1;
            ADCS(&registros[instruction.op1_value],registros[instruction.op2_value],registros[instruction.op3_value],flag);
        }
        if(instruction.op3_type=='#')//Si el operando 3 es un inmediato
        {
            registros[15]+=1;
            ADCS(&registros[instruction.op1_value],registros[instruction.op2_value],instruction.op3_value,flag);
        }
    }
    if(strcmp(instruction.mnemonic,"ANDS")==0)
    {
        if((instruction.op3_type=='N')&&(instruction.op2_type=='R'))
        {
            registros[15]+=1;
            *Mnem=(256<<6)|(instruction.op1_value)|(instruction.op2_value<<3);
            ANDS(&registros[instruction.op1_value],registros[instruction.op1_value],registros[instruction.op2_value],flag);
        }
        if((instruction.op3_type=='N')&&(instruction.op2_type=='#'))
        {
            registros[15]+=1;
            ANDS(&registros[instruction.op1_value],registros[instruction.op1_value],instruction.op2_value,flag);
        }
        if(instruction.op3_type=='R')
        {
            registros[15]+=1;
            ANDS(&registros[instruction.op1_value],registros[instruction.op2_value],registros[instruction.op3_value],flag);
        }
        if(instruction.op3_type=='#')
        {
            registros[15]+=1;
            ANDS(&registros[instruction.op1_value],registros[instruction.op2_value],instruction.op3_value,flag);
        }
    }
    if(strcmp(instruction.mnemonic,"EORS")==0)
    {
        if((instruction.op3_type=='N')&&(instruction.op2_type=='R'))
        {
            registros[15]+=1;
            *Mnem=(257<<6)|(instruction.op1_value)|(instruction.op2_value<<3);
            EORS(&registros[instruction.op1_value],registros[instruction.op1_value],registros[instruction.op2_value],flag);
        }
        if((instruction.op3_type=='N')&&(instruction.op2_type=='#'))
        {
            registros[15]+=1;
            EORS(&registros[instruction.op1_value],registros[instruction.op1_value],instruction.op2_value,flag);
        }
        if(instruction.op3_type=='R')
        {
            registros[15]+=1;
            EORS(&registros[instruction.op1_value],registros[instruction.op2_value],registros[instruction.op3_value],flag);
        }
        if(instruction.op3_type=='#')
        {
            registros[15]+=1;
            EORS(&registros[instruction.op1_value],registros[instruction.op2_value],instruction.op3_value,flag);
        }
    }
    if(strcmp(instruction.mnemonic,"MOVS")==0)
    {
        if(instruction.op2_type=='R')
        {
            registros[15]+=1;
            *Mnem=(instruction.op1_value)|(instruction.op2_value<<3);
            MOVS(&registros[instruction.op1_value],registros[instruction.op2_value],flag);
        }
        if(instruction.op2_type=='#')
        {
            registros[15]+=1;
            *Mnem=(4<<11)|(instruction.op1_value<<8)|(instruction.op2_value);
            MOVS(&registros[instruction.op1_value],instruction.op2_value,flag);
        }
    }
    if(strcmp(instruction.mnemonic,"MOV")==0)
    {
        if(instruction.op2_type=='R')
        {
            registros[15]+=1;
            *Mnem=(70<<8)|(instruction.op1_value)|(instruction.op2_value<<3);
            MOV(&registros[instruction.op1_value],registros[instruction.op2_value]);
        }
        if(instruction.op2_type=='#')
        {
            registros[15]+=1;
            MOV(&registros[instruction.op1_value],instruction.op2_value);
        }
    }
    if(strcmp(instruction.mnemonic,"ORRS")==0)
    {
        if((instruction.op3_type=='N')&&(instruction.op2_type=='R'))
        {
            registros[15]+=1;
            *Mnem=(268<<6)|(instruction.op1_value)|(instruction.op2_value<<3);
            ORRS(&registros[instruction.op1_value],registros[instruction.op1_value],registros[instruction.op2_value],flag);
        }
        if((instruction.op3_type=='N')&&(instruction.op2_type=='#'))
        {
            registros[15]+=1;
            ORRS(&registros[instruction.op1_value],registros[instruction.op1_value],instruction.op2_value,flag);
        }
        if(instruction.op3_type=='R')
        {
            registros[15]+=1;
            ORRS(&registros[instruction.op1_value],registros[instruction.op2_value],registros[instruction.op3_value],flag);
        }
        if(instruction.op3_type=='#')
        {
            registros[15]+=1;
            ORRS(&registros[instruction.op1_value],registros[instruction.op2_value],instruction.op3_value,flag);
        }
    }
    if(strcmp(instruction.mnemonic,"SUBS")==0)
    {
        if((instruction.op3_type=='N')&&(instruction.op2_type=='R'))
        {
            registros[15]+=1;
            SUBS(&registros[instruction.op1_value],registros[instruction.op1_value],registros[instruction.op2_value],flag);
        }
        if((instruction.op3_type=='N')&&(instruction.op2_type=='#'))
        {
            registros[15]+=1;
            *Mnem=(7<<11)|(instruction.op1_value<<8)|(instruction.op2_value);
            SUBS(&registros[instruction.op1_value],registros[instruction.op1_value],instruction.op2_value,flag);
        }
        if(instruction.op3_type=='R')
        {
            registros[15]+=1;
            *Mnem=(13<<9)|(instruction.op1_value)|(instruction.op2_value<<6)|(instruction.op3_value<<3);
            SUBS(&registros[instruction.op1_value],registros[instruction.op2_value],registros[instruction.op3_value],flag);
        }
        if(instruction.op3_type=='#')
        {
            registros[15]+=1;
            *Mnem=(15<<9)|(instruction.op1_value)|(instruction.op2_value<<3)|(instruction.op3_value<<6);
            SUBS(&registros[instruction.op1_value],registros[instruction.op2_value],instruction.op3_value,flag);
        }
    }
    if(strcmp(instruction.mnemonic,"LSLS")==0)
    {
        if((instruction.op3_type=='N')&&(instruction.op2_type=='R'))
        {
            registros[15]+=1;
            *Mnem=(258<<6)|(instruction.op1_value)|(instruction.op2_value<<3);
            LSLS(&registros[instruction.op1_value],registros[instruction.op1_value],registros[instruction.op2_value],flag);
        }
        if((instruction.op3_type=='N')&&(instruction.op2_type=='#'))
        {
            registros[15]+=1;
            LSLS(&registros[instruction.op1_value],registros[instruction.op1_value],instruction.op2_value,flag);
        }
        if(instruction.op3_type=='R')
        {
            registros[15]+=1;
            LSLS(&registros[instruction.op1_value],registros[instruction.op2_value],registros[instruction.op3_value],flag);
        }
        if(instruction.op3_type=='#')
        {
            registros[15]+=1;
            *Mnem=(instruction.op1_value)|(instruction.op2_value<<3)|(instruction.op3_value<<6);
            LSLS(&registros[instruction.op1_value],registros[instruction.op2_value],instruction.op3_value,flag);
        }
    }
    if(strcmp(instruction.mnemonic,"LSRS")==0)
    {
        if((instruction.op3_type=='N')&&(instruction.op2_type=='R'))
        {
            registros[15]+=1;
            *Mnem=(259<<6)|(instruction.op1_value)|(instruction.op2_value<<3);
            LSRS(&registros[instruction.op1_value],registros[instruction.op1_value],registros[instruction.op2_value],flag);
        }
        if((instruction.op3_type=='N')&&(instruction.op2_type=='#'))
        {
            registros[15]+=1;
            LSRS(&registros[instruction.op1_value],registros[instruction.op1_value],instruction.op2_value,flag);
        }
        if(instruction.op3_type=='R')
        {
            registros[15]+=1;
            LSRS(&registros[instruction.op1_value],registros[instruction.op2_value],registros[instruction.op3_value],flag);
        }
        if(instruction.op3_type=='#')
        {
            registros[15]+=1;
            *Mnem=(1<<11)|(instruction.op1_value)|(instruction.op2_value<<3)|(instruction.op3_value<<6);
            LSRS(&registros[instruction.op1_value],registros[instruction.op2_value],instruction.op3_value,flag);
        }
    }
    if(strcmp(instruction.mnemonic,"RORS")==0)
    {
        if(instruction.op2_type=='R')
        {
            registros[15]+=1;
            RORS(&registros[instruction.op1_value],registros[instruction.op2_value],flag);
        }
        if(instruction.op2_type=='#')
        {
            registros[15]+=1;
            RORS(&registros[instruction.op1_value],instruction.op2_value,flag);
        }
    }
    if(strcmp(instruction.mnemonic,"ASRS")==0)
    {
        if(instruction.op2_type=='R')
        {
            registros[15]+=1;
            *Mnem=(263<<6)|(instruction.op1_value)|(instruction.op2_value<<3);
            ASRS(&registros[instruction.op1_value],registros[instruction.op2_value],flag);
        }
        if(instruction.op2_type=='#')
        {
            registros[15]+=1;
            ASRS(&registros[instruction.op1_value],instruction.op2_value,flag);
        }
    }
    if(strcmp(instruction.mnemonic,"BICS")==0)
    {
        if(instruction.op2_type=='R')
        {
            registros[15]+=1;
            *Mnem=(270<<6)|(instruction.op1_value)|(instruction.op2_value<<3);
            BICS(&registros[instruction.op1_value],registros[instruction.op2_value],flag);
        }
        if(instruction.op2_type=='#')
        {
            registros[15]+=1;
            BICS(&registros[instruction.op1_value],instruction.op2_value,flag);
        }
    }
    if(strcmp(instruction.mnemonic,"NOP")==0)
    {
        registros[15]+=1;
        *Mnem=-16640;
    }
    if(strcmp(instruction.mnemonic,"MVNS")==0)
    {
        if(instruction.op2_type=='R')
        {
            registros[15]+=1;
            *Mnem=(271<<6)|(instruction.op1_value)|(instruction.op2_value<<3);
            MVNS(&registros[instruction.op1_value],registros[instruction.op2_value],flag);
        }
        if(instruction.op2_type=='#')
        {
            registros[15]+=1;
            MVNS(&registros[instruction.op1_value],instruction.op2_value,flag);
        }
    }
    if(strcmp(instruction.mnemonic,"CMN")==0)
    {
        if((instruction.op1_type=='R')&&(instruction.op2_type=='R'))
        {
            registros[15]+=1;
            *Mnem=(267<<6)|(instruction.op1_value)|(instruction.op2_value<<3);
            CMN(registros[instruction.op1_value],registros[instruction.op2_value],flag);
        }
        if((instruction.op1_type=='R')&&(instruction.op2_type=='#'))
        {
            registros[15]+=1;
            CMN(registros[instruction.op1_value],instruction.op2_value,flag);
        }
        if((instruction.op1_type=='#')&&(instruction.op2_type=='R'))
        {
            registros[15]+=1;
            CMN(instruction.op1_value,registros[instruction.op2_value],flag);
        }
        if((instruction.op1_type=='#')&&(instruction.op2_type=='#'))
        {
            registros[15]+=1;
            CMN(instruction.op1_value,instruction.op2_value,flag);
        }
    }
    if(strcmp(instruction.mnemonic,"CMP")==0)
    {
        if((instruction.op1_type=='R')&&(instruction.op2_type=='R'))
        {
            registros[15]+=1;
            *Mnem=(266<<6)|(instruction.op1_value)|(instruction.op2_value<<3);
            CMP(registros[instruction.op1_value],registros[instruction.op2_value],flag);
        }
        if((instruction.op1_type=='R')&&(instruction.op2_type=='#'))
        {
            registros[15]+=1;
            *Mnem=(5<<11)|(instruction.op1_value<<8)|(instruction.op2_value);
            CMP(registros[instruction.op1_value],instruction.op2_value,flag);
        }
        if((instruction.op1_type=='#')&&(instruction.op2_type=='R'))
        {
            registros[15]+=1;
            CMP(instruction.op1_value,registros[instruction.op2_value],flag);
        }
        if((instruction.op1_type=='#')&&(instruction.op2_type=='#'))
        {
            registros[15]+=1;
            CMP(instruction.op1_value,instruction.op2_value,flag);
        }
    }
    if(strcmp(instruction.mnemonic,"RSBS")==0)
    {
        if(instruction.op2_type=='R')
        {
            registros[15]+=1;
            *Mnem=(265<<6)|(instruction.op1_value)|(instruction.op2_value<<3);
            RSBS(&registros[instruction.op1_value],registros[instruction.op2_value],flag);
        }
        if(instruction.op2_type=='#')
        {
            registros[15]+=1;
            RSBS(&registros[instruction.op1_value],instruction.op2_value,flag);
        }
    }
    if(strcmp(instruction.mnemonic,"REV")==0)
    {
        if(instruction.op2_type=='N')
        {
            registros[15]+=1;
            REV(&registros[instruction.op1_value],registros[instruction.op1_value]);
        }
        else
        {
            registros[15]+=1;
            *Mnem=(744<<6)|(instruction.op1_value)|(instruction.op2_value<<3);
            REV(&registros[instruction.op1_value],registros[instruction.op2_value]);
        }
    }
    if(strcmp(instruction.mnemonic,"REV16")==0)
    {
        if(instruction.op2_type=='N')
        {
            registros[15]+=1;
            REV16(&registros[instruction.op1_value],registros[instruction.op1_value]);
        }
        else
        {
            registros[15]+=1;
            *Mnem=(745<<6)|(instruction.op1_value)|(instruction.op2_value<<3);
            REV16(&registros[instruction.op1_value],registros[instruction.op2_value]);
        }
    }
    if(strcmp(instruction.mnemonic,"REVSH")==0)
    {
        if(instruction.op2_type=='N')
        {
            registros[15]+=1;
            REVSH(&registros[instruction.op1_value],registros[instruction.op1_value]);
        }
        else
        {
            registros[15]+=1;
            *Mnem=(747<<6)|(instruction.op1_value)|(instruction.op2_value<<3);
            REVSH(&registros[instruction.op1_value],registros[instruction.op2_value]);
        }
    }
    if(strcmp(instruction.mnemonic,"TST")==0)
    {
        if(instruction.op2_type=='N')
        {
            registros[15]+=1;
            TST(&registros[instruction.op1_value],registros[instruction.op1_value]);
        }
        else
        {
            registros[15]+=1;
            *Mnem=(264<<6)|(instruction.op1_value)|(instruction.op2_value<<3);
            TST(&registros[instruction.op1_value],registros[instruction.op2_value]);
        }
    }
    if(strcmp(instruction.mnemonic,"MUL")==0)
    {
        if((instruction.op3_type=='N')&&(instruction.op2_type=='R'))
        {
            registros[15]+=1;
            MUL(&registros[instruction.op1_value],registros[instruction.op1_value],registros[instruction.op2_value],flag);
        }
        if((instruction.op3_type=='N')&&(instruction.op2_type=='#'))
        {
            registros[15]+=1;
            MUL(&registros[instruction.op1_value],registros[instruction.op1_value],instruction.op2_value,flag);
        }
        if(instruction.op3_type=='R')
        {
            registros[15]+=1;
            *Mnem=(269<<6)|(instruction.op1_value)|(instruction.op2_value<<3);
            MUL(&registros[instruction.op1_value],registros[instruction.op2_value],registros[instruction.op3_value],flag);
        }
        if(instruction.op3_type=='#')
        {
            registros[15]+=1;
            MUL(&registros[instruction.op1_value],registros[instruction.op2_value],instruction.op3_value,flag);
        }
    }

      /* SALTOS DE LINEA */

      /* Se efectua la operacion correspondiente a la condicon del mnemonico */

    if(strcmp(instruction.mnemonic,"B")==0)
    {
        *Mnem=(13<<12)/*(<<8)*/|(instruction.op1_value);
        B(&registros[15],instruction.op1_value);
    }

    if(strcmp(instruction.mnemonic,"BEQ")==0) /* Salta si la bandera de Zero esta activa */
    {
        *Mnem=(13<<12)|(instruction.op1_value);
        BEQ(&registros[15],instruction.op1_value,flag);
    }

    if(strcmp(instruction.mnemonic,"BNE")==0) /* Salta si la bandera de Zero no esta activa */
    {
        *Mnem=(13<<12)|(1<<8)|(instruction.op1_value);
        BNE(&registros[15],instruction.op1_value,flag);
    }

    if(strcmp(instruction.mnemonic,"BCS")==0) /* Salta si la bandera de Carry esta activa */
    {
        *Mnem=(13<<12)|(2<<8)|(instruction.op1_value);
        BCS(&registros[15],instruction.op1_value,flag);
    }

    if(strcmp(instruction.mnemonic,"BCC")==0) /* Salta si la bandera de Carry no esta activa */
    {
        *Mnem=(13<<12)|(3<<8)|(instruction.op1_value);
        BCC(&registros[15],instruction.op1_value,flag);
    }

    if(strcmp(instruction.mnemonic,"BMI")==0) /* Salta si la bandera de Negativo esta activa */
    {
        *Mnem=(13<<12)|(4<<8)|(instruction.op1_value);
        BMI(&registros[15],instruction.op1_value,flag);
    }

    if(strcmp(instruction.mnemonic,"BPL")==0) /* Salta si la bandera de Negativo no esta activa */
    {
        *Mnem=(13<<12)|(5<<8)|(instruction.op1_value);
        BPL(&registros[15],instruction.op1_value,flag);
    }

    if(strcmp(instruction.mnemonic,"BVS")==0) /* Salta si la bandera de Sobreflujo esta activa */
    {
        *Mnem=(13<<12)|(6<<8)|(instruction.op1_value);
        BVS(&registros[15],instruction.op1_value,flag);
    }

    if(strcmp(instruction.mnemonic,"BVC")==0) /* Salta si la bandera de Sobreflujo no esta activa */
    {
        *Mnem=(13<<12)|(7<<8)|(instruction.op1_value);
        BVC(&registros[15],instruction.op1_value,flag);
    }

    if(strcmp(instruction.mnemonic,"BHI")==0) /* Salta si la bandera de Carry esta activa y la bandera de Zero no esta acativa */
    {
        *Mnem=(13<<12)|(8<<8)|(instruction.op1_value);
        BHI(&registros[15],instruction.op1_value,flag);
    }

    if(strcmp(instruction.mnemonic,"BLS")==0) /* Salta si la bandera de Carry no esta activa y la bandera de Zero esta acativa */
    {
        *Mnem=(13<<12)|(9<<8)|(instruction.op1_value);
        BLS(&registros[15],instruction.op1_value,flag);
    }

    if(strcmp(instruction.mnemonic,"BGE")==0) /* Salta si la bandera de Sobreflujo y la bandera de Negativo estan ambas activas o ambas inactivas */
    {
        *Mnem=(13<<12)|(10<<8)|(instruction.op1_value);
        BGE(&registros[15],instruction.op1_value,flag);
    }

    if(strcmp(instruction.mnemonic,"BLT")==0) /* Salta si la bandera de Sobleflijo esta activa y la de NEgativo esta inactiva, o viceversa*/
    {
        *Mnem=(13<<12)|(11<<8)|(instruction.op1_value);
        BLT(&registros[15],instruction.op1_value,flag);
    }

    if(strcmp(instruction.mnemonic,"BGT")==0) /* Salta si la bandera de Carry esta activa y la bandera de Zero no esta acativa */
    {
        *Mnem=(13<<12)|(12<<8)|(instruction.op1_value);
        BGT(&registros[15],instruction.op1_value,flag);
    }

    if(strcmp(instruction.mnemonic,"BLE")==0) /* Salta si la bandera de Zero esta inactiva y la bandera de Negatvo esta en el mismo estado de la de Sobreflujo*/
    {
        *Mnem=(13<<12)|(13<<8)|(instruction.op1_value);
        BLE(&registros[15],instruction.op1_value,flag);
    }

    if(strcmp(instruction.mnemonic,"BLA")==0) /* Salta un inmediato en PC */
    {
        *Mnem=(13<<12)|(14<<8)|(instruction.op1_value);
        BLA(&registros[15],instruction.op1_value);
    }

    if(strcmp(instruction.mnemonic,"BL")==0) /*Esta funcion envia al PC a una direccion inmediata y manda al LR a la siguiente instruccion teniendo en cuenta
                                                la consideracion de que PC emplea 32 bits*/
    {

        BL(&registros[15],&registros[14],instruction.op1_value);
    }

    if(strcmp(instruction.mnemonic,"BX")==0) /*Esta funcion guardo el contenido de un registro en el PC y pone a LR en la siguiente instruccion teniendo en
                                             cuenta la consideracion de que PC emplea 32 bits*/
    {
        if(instruction.op1_type=='L')
        {
            BX(&registros[15],registros[14]);
        }
        else
        {
            *Mnem=(142<<7)|(instruction.op1_value<<3);
            BX(&registros[15],registros[instruction.op1_value]);
        }
    }

    if(strcmp(instruction.mnemonic,"BLX")==0) /*Esta funcion guardo el contenido de un registro en el PC y pone a LR en la siguiente instruccion teniendo
                                                en cuenta la consideracion de que PC emplea 32 bits*/
    {
        if(instruction.op1_type=='L')
        {   *Mnem=(143<<7)|(instruction.op1_value<<3);
            BLX(&registros[15],&registros[14],registros[14]);
        }
        else
        {
            *Mnem=(143<<7)|(instruction.op1_value<<3);
            BLX(&registros[15],&registros[14],registros[instruction.op1_value]);
        }
    }
    if(strcmp(instruction.mnemonic,"SBCS")==0) //Si la intruccion es ADCS :
    {
        if((instruction.op3_type=='N')&&(instruction.op2_type=='R')) // Si en el operando 3 no tengo nada y el operando 2 es un reguistro
        {
            registros[15]+=1;
            *Mnem=(262<<6)|(instruction.op1_value)|(instruction.op2_value<<3);
            SBCS(&registros[instruction.op1_value],registros[instruction.op1_value],registros[instruction.op2_value],flag);
        }
        if((instruction.op3_type=='N')&&(instruction.op2_type=='#')) // Si en el operando 3 no hay nada y el operando 2 es un inmediato
        {
            registros[15]+=1;
            SBCS(&registros[instruction.op1_value],registros[instruction.op1_value],instruction.op2_value,flag);
        }
        if(instruction.op3_type=='R') // Si el operando 3 es un registro
        {
            registros[15]+=1;
            SBCS(&registros[instruction.op1_value],registros[instruction.op2_value],registros[instruction.op3_value],flag);
        }
        if(instruction.op3_type=='#')//Si el operando 3 es un inmediato
        {
            registros[15]+=1;
            SBCS(&registros[instruction.op1_value],registros[instruction.op2_value],instruction.op3_value,flag);
        }
    }
    if (strcmp(instruction.mnemonic,"PUSH")==0)
    {
        int i;int16_t aux;
        for(i=0;i<=15;i++)
        {
            aux=(instruction.registers_list[i]<<i);
        }
        registros[15]+=1;
        *Mnem=(aux&0x00FF)|(aux&0x2000);
        PUSH(registros,MemRAM, instruction.registers_list);
    }
    if (strcmp(instruction.mnemonic,"POP")==0)
    {
        int i;int16_t aux;
        for(i=0;i<=15;i++)
        {
            aux=(instruction.registers_list[i]<<i);
        }
        registros[15]+=1;
        *Mnem=(aux&0x00FF)|(aux&0x4000);
        POP(registros,MemRAM, instruction.registers_list);
    }

    if(strcmp(instruction.mnemonic,"LDR")==0)
    {
        if((instruction.op3_type=='#')&&(instruction.op2_type=='R')&&(instruction.op2_value==13))
        {
            if(instruction.op3_value<256)
            {
                registros[15]+=1;
                imm32=(uint32_t)(instruction.op3_value<<2);
                LDR(&registros[instruction.op1_value],registros[instruction.op2_value]&0xFF,imm32,MemRAM);
            }
        }
        if((instruction.op3_type=='#')&&(instruction.op2_type=='R')&&(instruction.op2_value==15))
        {
            if(instruction.op3_value<256)
            {
                registros[15]+=1;
                imm32=(uint32_t)(instruction.op3_value<<2);
                LDR(&registros[instruction.op1_value],registros[instruction.op2_value]&0xFF,imm32,MemRAM);
            }
        }
        if((instruction.op3_type=='#')&&(instruction.op2_type=='R'))
        {
            if(instruction.op3_value<32)
            {
                registros[15]+=1;
                imm32=(uint32_t)(instruction.op3_value<<2);
                LDR(&registros[instruction.op1_value],registros[instruction.op2_value]&0xFF,imm32,MemRAM);
            }
        }
        if((instruction.op3_type=='R')&&(instruction.op2_type=='R'))
        {
            registros[15]+=1;
            *Mnem=(44<<9)|(instruction.op1_value)|(instruction.op2_value<<3)|(instruction.op3_value<<6);
            LDR(&registros[instruction.op1_value],registros[instruction.op2_value],registros[instruction.op3_value],MemRAM);
        }
    }

    if(strcmp(instruction.mnemonic,"LDRB")==0)
    {
        uint32_t suma;
        if((instruction.op3_type=='#')&&(instruction.op2_type=='R'))
        {
            if(instruction.op3_value<32)
            {
                *Mnem=(15<<11)|(instruction.op1_value)|(instruction.op2_value)<<3|(instruction.op3_value)<<6;
                registros[15]+=1;
                imm32=(uint32_t)(instruction.op3_value<<2);
                suma=registros[instruction.op2_value]+imm32;
                if((suma>=0x20000000)&&(suma<=0x200000FF))
                {
                    LDRB(&registros[instruction.op1_value],(registros[instruction.op2_value]&0xFF),imm32,MemRAM);
                }
                if(suma>=0x40000000)
                {
                    IOAccess(suma&0xFF,&registros[instruction.op1_value],Read);
                }
            }
        }
        if((instruction.op3_type=='R')&&(instruction.op2_type=='R'))
        {
            registros[15]+=1;
            *Mnem=(46<<9)|(instruction.op1_value)|(instruction.op2_value)<<3|(instruction.op3_value)<<6;
            LDR(&registros[instruction.op1_value],registros[instruction.op2_value],registros[instruction.op3_value],MemRAM);
            suma=registros[instruction.op2_value]+registros[instruction.op3_value];
            if((suma>=0x20000000)&&(suma<=0x200000FF))
            {
                LDRB(&registros[instruction.op1_value],registros[instruction.op2_value]&0xFF,registros[instruction.op3_value]&0xFF,MemRAM);
            }
            if(suma>=0x40000000)
            {
                    IOAccess(suma&0xFF, &registros[instruction.op1_value],Read);
            }
        }
    }
    if(strcmp(instruction.mnemonic,"LDRH")==0)
    {
        if((instruction.op3_type=='#')&&(instruction.op2_type=='R'))
        {
            if(instruction.op3_value<32)
            {
                *Mnem=(17<<11)|(instruction.op1_value)|(instruction.op2_value)<<3|(instruction.op3_value)<<6;
                registros[15]+=1;
                imm32=(uint32_t)(instruction.op3_value<<2);
                LDRH(&registros[instruction.op1_value],registros[instruction.op2_value],imm32,MemRAM);
            }
        }
         if((instruction.op3_type=='R')&&(instruction.op2_type=='R'))
        {
            registros[15]+=1;
            *Mnem=(45<<9)|(instruction.op1_value)|(instruction.op2_value)<<3|(instruction.op3_value)<<6;
            LDRH(&registros[instruction.op1_value],registros[instruction.op2_value],registros[instruction.op3_value],MemRAM);
        }

    }

    if(strcmp(instruction.mnemonic,"LDRSB")==0)
    {
        if((instruction.op3_type=='R')&&(instruction.op2_type=='R'))
        {
            registros[15]+=1;
            *Mnem=(43<<9)|(instruction.op1_value)|(instruction.op2_value)<<3|(instruction.op3_value)<<6;
            LDRSB(&registros[instruction.op1_value],registros[instruction.op2_value],registros[instruction.op3_value],MemRAM);

        }
    }

    if(strcmp(instruction.mnemonic,"LDRSH")==0)
    {
        if((instruction.op2_type=='R')&&(instruction.op3_type=='R'))
        {
            registros[15]+=1;
            *Mnem=(47<<9)|(instruction.op1_value)|(instruction.op2_value)<<3|(instruction.op3_value)<<6;
            LDRSH(&registros[instruction.op1_value],registros[instruction.op2_value],registros[instruction.op3_value],MemRAM);
        }
    }

    if(strcmp(instruction.mnemonic,"STR")==0)
    {
        if((instruction.op3_type=='#')&&(instruction.op2_type=='R'))
        {
            if(instruction.op3_value<32)
            {
                registros[15]+=1;
                *Mnem=(12<<11)|(instruction.op1_value)|(instruction.op2_value)<<3|(instruction.op3_value)<<6;
                imm32=(uint32_t)(instruction.op3_value<<2);
                STR(&registros[instruction.op1_value],registros[instruction.op2_value],imm32,MemRAM);
            }
        }
        if(instruction.op3_value<256)
        {
            registros[15]+=1;
            *Mnem=(18<<11)|(instruction.op1_value)<<8|(instruction.op3_value);
            imm32=(uint32_t)(instruction.op3_value<<2);
            STR(&registros[instruction.op1_value],registros[instruction.op2_value],imm32,MemRAM);
        }
         if((instruction.op3_type=='R')&&(instruction.op2_type=='R'))
        {
            registros[15]+=1;
            *Mnem=(47<<9)|(instruction.op1_value)|(instruction.op2_value)<<3|(instruction.op3_value)<<6;
            STR(&registros[instruction.op1_value],registros[instruction.op2_value],registros[instruction.op3_value],MemRAM);
        }
    }
    if(strcmp(instruction.mnemonic,"STRB")==0)
    {
        uint32_t suma;
         if((instruction.op3_type=='#')&&(instruction.op2_type=='R'))
        {
            if(instruction.op3_value<32)
            {
                registros[15]+=1;
                *Mnem=(14<<11)|(instruction.op1_value)|(instruction.op2_value)<<3|(instruction.op3_value)<<6;
                imm32=(uint32_t)(instruction.op3_value<<2);
                suma=registros[instruction.op2_value]+imm32;
                if((suma>=0x20000000)&&(suma<=0x200000FF))
                {
                    STRB(&registros[instruction.op1_value],registros[instruction.op2_value]&0xFF,imm32,MemRAM);
                }
                if(suma>=0x40000000)
                {
                    IOAccess(suma&0xFF, &registros[instruction.op1_value],Write);
                }
            }
        }
        if((instruction.op3_type=='R')&&(instruction.op2_type=='R'))
        {
            registros[15]+=1;
            *Mnem=(42<<9)|(instruction.op1_value)|(instruction.op2_value)<<3|(instruction.op3_value)<<6;
            STRB(registros[instruction.op1_value],registros[instruction.op2_value],registros[instruction.op3_value],MemRAM);
            suma=registros[instruction.op2_value]+registros[instruction.op3_value];
            if((suma>=0x20000000)&&(suma<=0x200000FF))
            {
                STRB(&registros[instruction.op1_value],registros[instruction.op2_value]&0xFF,registros[instruction.op3_value]&0xFF,MemRAM);
            }
            if(suma>=0x40000000)
            {
                IOAccess(suma&0xFF, &registros[instruction.op1_value],Write);
            }
        }
    }
    if(strcmp(instruction.mnemonic,"STRH")==0)
    {
         if((instruction.op3_type=='#')&&(instruction.op2_type=='R'))
        {
            if(instruction.op3_value<32)
            {
                registros[15]+=1;
                *Mnem=(16<<11)|(instruction.op1_value)|(instruction.op2_value)<<3|(instruction.op3_value)<<6;
                imm32=(uint32_t)(instruction.op3_value<<2);
                STRH(registros[instruction.op1_value],registros[instruction.op2_value],imm32,MemRAM);
            }
        }

         if((instruction.op3_type=='R')&&(instruction.op2_type=='R'))
        {
            registros[15]+=1;
            *Mnem=(41<<9)|(instruction.op1_value)|(instruction.op2_value)<<3|(instruction.op3_value)<<6;
            STRH(registros[instruction.op1_value],registros[instruction.op2_value],registros[instruction.op3_value],MemRAM);
        }
    }
}

instruction_t getInstruction(char* instStr)
{
	instruction_t instruction=
	{
		.registers_list = {0},
		.op3_type  = 'N',
		.op3_value = 0
	};
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
				if(split[0] == '{'){
					instruction.op1_type  = split[0];
					split++;
					do{
						if(split[0]=='L')
							instruction.registers_list[14] = 1;
						else if(split[0]=='P')
							instruction.registers_list[15] = 1;
						else
							instruction.registers_list[(uint8_t)strtoll(split+1, NULL, 0)] = 1;

						split = strtok(NULL, ",");
					}while(split != NULL);
				}else{
					instruction.op1_type  = split[0];
					instruction.op1_value = (uint32_t)strtoll(split+1, NULL, 0);
				}
				break;

			case 2:
			    if(split[0]=='[')
                    split++;

				instruction.op2_type  = split[0];
				instruction.op2_value = (uint32_t)strtoll(split+1, NULL, 0);
				break;

			case 3:
				instruction.op3_type  = split[0];
				instruction.op3_value = (uint32_t)strtoll(split+1, NULL, 0);
				break;
		}
		if(split != NULL){
			split = strtok(NULL, " ,.");
			num++;
		}
	}

	if(instruction.op1_type == 'L'){
		instruction.op1_value = 14;
		instruction.op1_type = 'R';
	}

	if(instruction.op1_type == '{'){
		instruction.op1_type = 'P';
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
