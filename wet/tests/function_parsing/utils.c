#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "utils.h"

unsigned long get_function_address(char * function_name , char* file_name)
{
    FILE* my_file = fopen(file_name, "rb");
    if(!my_file)
    {
        exit(1); 
    }
    Elf64_Ehdr elf_hdr;
    fread(&elf_hdr, sizeof(elf_hdr) , 1, my_file); 
    fseek(my_file, elf_hdr.e_shoff, SEEK_SET); 
    Elf64_Half shstrtbl = elf_hdr.e_shstrndx;
    Elf64_Shdr symbol_table_sh;
    
    int j = 0;
    while(j < shstrtbl) 
    {
        fread(&symbol_table_sh, sizeof(symbol_table_sh) , 1, my_file); 
        if(ELF64_ST_TYPE(symbol_table_sh.sh_type) == 2) 
        {
            int num_of_symbols = symbol_table_sh.sh_size/sizeof(Elf64_Sym);
            Elf64_Shdr section_header_string;
            fseek(my_file, elf_hdr.e_shoff, SEEK_SET); // jump to sh begin
            fseek(my_file, symbol_table_sh.sh_link * sizeof(section_header_string) , SEEK_CUR);
            fread(&section_header_string, sizeof(section_header_string) , 1, my_file); 
            int elf_sym_size = sizeof(Elf64_Sym);
            Elf64_Sym* table_symbol = malloc( elf_sym_size* num_of_symbols);
            if(table_symbol == NULL )
            {
                fclose(my_file);
                exit(1);
            }
           fseek(my_file, symbol_table_sh.sh_offset , SEEK_SET);
            fread(table_symbol, sizeof(Elf64_Sym) , num_of_symbols, my_file); 
            char c;
            for (int i = 0; i < num_of_symbols; i++)
            {
                unsigned long  temp = section_header_string.sh_offset + table_symbol[i].st_name;
                if(temp != 0) //in case symbol  holds a string 
                {
                    fseek(my_file, section_header_string.sh_offset + table_symbol[i].st_name, SEEK_SET);
                    int loop_cnt = -1;
                    do
                    {  
                        fread(&c, 1 , 1, my_file); 
                        loop_cnt++;
                    } while (function_name[j] != '\0' && function_name[j] == c && c != '\0');

                    if(c != function_name[j])
                        continue; 
                    else 
                    {
                        if(ELF64_ST_BIND(table_symbol[i].st_info) == 0) 
                        {
                            printf("PRF:: local found!\n");
                            free(table_symbol);
                            fclose(my_file);
                            exit(1);
                        }
                        else
                        {
                            unsigned long temp = table_symbol[i].st_value;
                            free(table_symbol);
                            fclose(my_file);
                            printf("PRF:: global found!\n");
                            return temp;
                        }
                    }
                }
            }
            free(table_symbol);
        }
        j++;
    }
    printf("PRF:: not found!");
    fclose(my_file);
    exit(1);
}