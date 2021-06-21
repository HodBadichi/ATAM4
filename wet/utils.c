#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "utils.h"
//TODO:
// try to make comparision more efficient
// check Y 'f6' returned
// CAN WE ASSUME FUNCTION IS OF TYPE 'FUNK' = 2 ?
// build the debugger
// add arguments

unsigned long get_function_address(char * function_name , char* file_name)
{
    FILE* file = fopen(file_name, "rb");
    if(!file)
    {
        exit(1); //error - exit;
    }
    Elf64_Ehdr elf;
    fread(&elf, sizeof(elf) , 1, file); //read elf headers
    fseek(file, elf.e_shoff, SEEK_SET); //seek to section headers
    Elf64_Shdr sym_tab_section_header;
    Elf64_Half shstrtbl = elf.e_shstrndx;

    int i = 0;
    while(i < shstrtbl) //scan all entries of section headers
    {
        fread(&sym_tab_section_header, sizeof(sym_tab_section_header) , 1, file); //read section header
        if(ELF64_ST_TYPE(sym_tab_section_header.sh_type) == 2) //2 = symtan -> check if current section is symtab
        {
                // we now have symtab section header in 'section_header'. lets find string table using sh_link:
            //first read the 'sh_link' from sym_tab section header - it points to str_tab:
            Elf64_Shdr section_header_str_tbl;
            fseek(file, elf.e_shoff, SEEK_SET); //seek to section headers beginning
            fseek(file, sym_tab_section_header.sh_link * sizeof(section_header_str_tbl) , SEEK_CUR);
            fread(&section_header_str_tbl, sizeof(section_header_str_tbl) , 1, file); //read string table
            //now we have string table section header in 'section_header_str_tbl' ;
            //read all the entries in symbol table and compare to function name:
            int size = sym_tab_section_header.sh_size/sizeof(Elf64_Sym);
            Elf64_Sym * symbol_tbl = malloc(sizeof(Elf64_Sym) * size);
            if(!symbol_tbl)
            {
                exit(1);
            }
            fseek(file, sym_tab_section_header.sh_offset , SEEK_SET);
            fread(symbol_tbl, sizeof(Elf64_Sym) , size, file); //read symbol table
            char c;
            for (int i = 0; i < size; i++)
            {
                unsigned long  temp = section_header_str_tbl.sh_offset + symbol_tbl[i].st_name;
                if(temp != 0) //in case symbol  holds a string 
                {
                    fseek(file, section_header_str_tbl.sh_offset + symbol_tbl[i].st_name, SEEK_SET);
                    int j = -1;
                    do
                    {  
                        fread(&c, 1 , 1, file); //read symbol table
                        j++;
                    } while (c != '\0' && function_name[j] != '\0' && function_name[j] == c);

                    if(c != function_name[j])
                        continue; //no match.
                    else //we have a match
                    {
                        if(ELF64_ST_BIND(symbol_tbl[i].st_info) == 0) //0 = LOCAL
                        {
                            printf("PRF:: local found!");
                            free(symbol_tbl);
                            exit(1);
                        }
                        else
                        {
                            unsigned long temp = symbol_tbl[i].st_value;
                            free(symbol_tbl);
                            return temp;
                        }
                    }
                }
            }
            free(symbol_tbl);
        }
        i++;//iterate through SH table       
    }
    printf("PRF:: not found!");
    exit(1);
}