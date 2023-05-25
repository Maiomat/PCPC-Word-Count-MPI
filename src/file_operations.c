#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>
#include <errno.h>

#include "mycollective.h"

File_inf * get_info_file(char * file_path){
    struct stat sb;
    File_inf * file = (File_inf *) malloc(sizeof(File_inf));

    if(stat(file_path, &sb) != -1){
        file->total_size = sb.st_size;
        file->path = malloc(sizeof(char) * strlen(file_path) + 1);
        if (file->path != NULL){
            strncpy(file->path, file_path, strlen(file_path) + 1);
        } else {
            free(file);
            file = NULL;
        }
    }
    return file;
}

//Funzione che crea la lista di oggetti file_info
GList * get_directory_files_info(char * dir_paths, double *files_size){
    GList* list = NULL;
    DIR *d;
    struct dirent *dir;
    char file_path[260];
    char path_sep[]={'/','\0'};

    //apro la directory
    d = opendir(dir_paths);

    if (d)
    {
        File_inf * temp_info;

        while ((dir = readdir(d)) != NULL) // scorro l'intero contenuto della directory
        {
            if(dir-> d_type != DT_DIR){
                //path assoluta del file per ottenere le informazioni
                snprintf(file_path, sizeof(file_path), "%s%s%s", dir_paths, path_sep, dir->d_name);
            
                temp_info = get_info_file(file_path);
                if (temp_info != NULL) {
                    *files_size += temp_info->total_size;
                    list = g_list_append(list, temp_info);
                }
            }
        }
        closedir(d);
    } else if (ENOENT == errno){
        return NULL;
    }

    return list;
}

void free_files_info(GList * list, int num){
    GList * elem = list;
    for(int i=0; i<num; i++){
            File_inf * f = elem->data;
            free(f->path);
            free(elem->data);
            elem = elem->next;
    }
    g_list_free(list);
}

