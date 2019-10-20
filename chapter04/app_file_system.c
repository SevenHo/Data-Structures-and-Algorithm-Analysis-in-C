#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef __BOOL__
#define false 0
#define true 1
#endif
typedef int bool;

typedef char ElementType;
typedef struct t_entry *entry;
typedef entry Tree;

typedef struct t_entry
{
    ElementType e[20];
    entry parent;
    entry first_child;
    entry next_sibling;
} aEntry;

/**
 * 1.创建目录
 * 2.删除一个目录
 * 3.创建一个文件
 * 4.删除一个文件
 * 5.打印一个目录
 */

/*操作命令*/
static char commands_list[][10] = {"mkdir", "cd", "tree", "tuch", "ls", "exit", "rm"};

/**
 * 当前目录下查找目录或文件
 */
entry find(char *name, entry self)
{
    if (!self)
    {
        return NULL;
    }
    if (strcmp(name, "..*") == 0)
    {
        return self->parent;
    }
    entry tmpcell = self->first_child;
    while (tmpcell)
    {
        if (strcmp(tmpcell->e, name) == 0)
            break;
        tmpcell = tmpcell->next_sibling;
    }
    return tmpcell;
}

/**
 * 创建目录或文件
 */
entry make_dir_file(char *name, bool isDir, entry self)
{
    if (isDir)
    {
        strcat(name, "*");
    }
    else
    {
        char *ext = strrchr(name, '.');
        if (!(ext && ((ext - name) != strlen(name) - 1))) /*没有后扩展名*/
            strcat(name, ".txt");
    }
    if (!find(name, self)) /*文件是否存在*/
    {
        entry p = (entry)malloc(sizeof(aEntry));
        strcpy(p->e, name);
        p->parent = NULL;
        p->first_child = NULL;
        p->next_sibling = NULL;
        return p;
    }
    else
    {
        printf("the file or directory exists already\n");
        return NULL;   
    }
}


bool is_dir(entry en)
{
    return *(en->e + strlen(en->e) - 1) == '*';
}

void delete_dir_file(entry en,entry self)
{
    entry tmpcell = self->first_child;
    if(tmpcell == en){
        self->first_child = tmpcell->next_sibling;
        free(tmpcell);
        return ;
    }
    entry tmpcell_before = tmpcell;
    while (tmpcell != en)   
    {
        tmpcell_before = tmpcell_before;
        tmpcell = tmpcell->next_sibling;
    }
    if (tmpcell)    
    {
        tmpcell_before ->next_sibling = tmpcell->next_sibling;
        free(tmpcell);
    }
 
}

/**
 * 当前目录下插入一个子文件夹或子文件
 */
void insert_dir_file(entry child, entry self)
{
    if(child){
        entry tmpcell = self->first_child;
        child->next_sibling = tmpcell;
        child->parent = self;
        self->first_child = child;
    }
}

/**
 * 获取目录名
 */
char *get_dir_name(char dir[20], char name[20])
{
    strncpy(name, dir, strlen(dir) - 1);
    return name;
}

/**
 * 打印文件或目录名
 */
void print_name(entry en, int depth)
{
    int d = depth;
    char name[20] = "";

    while (d--)
    {
        printf("  |");
    }
    if (depth)
    {
        if (is_dir(en))
        {
            printf("--%s\n", get_dir_name(en->e, name));
        }
        else
        {
            printf("--%s\n", en->e);
        }
    }
    else
    {

        printf("%s\n", get_dir_name(en->e, name));
    }
}

/**
 * 当前绝对路径
 */
void absolut_path(entry en)
{
    // entry tmpcell = root ;
    // if (root)
    // {
    //     while (tmpcell && tmpcell != en)
    //     {
    //         tmpcell = tmpcell->next_sibling;
    //     }
    //     char name[20] = "";
    //     if(tmpcell)
    //     {
    //         printf("%s>",get_dir_name(tmpcell->e,name));
    //     }else
    //     {
    //         printf("%s/",get_dir_name(root->e,name));
    //         absolut_path(root->first_child,en);
    //     }

    // }

    if (en)
    {
        absolut_path(en->parent);
        char name[20] = "";
        printf("/%s", get_dir_name(en->e, name));
    }
}

void commands_line(entry en, char *host_name)
{
    printf("<%s:", host_name);
    absolut_path(en);
    printf("> ");
}

/**
 * 列出目录结构
 */
void list_dir(Tree dir, int depth)
{
    if (dir)
    {
        print_name(dir, depth);
        if (is_dir(dir))
        {
            entry tmpchild = dir->first_child;
            while (tmpchild)
            {
                list_dir(tmpchild, depth + 1);
                tmpchild = tmpchild->next_sibling;
            }
        }
    }
}

/**
 * ls 子文件
 */
void ls_dir(entry parent)
{
    entry tmpcell = parent->first_child;
    while (tmpcell)
    {
        if (is_dir(tmpcell))
        {
            char name[20] = "";
            printf("%s/ ", get_dir_name(tmpcell->e, name));
        }
        else
        {
            printf("%s  ", tmpcell->e);
        }

        tmpcell = tmpcell->next_sibling;
    }
    printf("\n");
}

/**
 * cd 目录
 */
entry cd_dir(char dir[20], entry self)
{

    entry tmpdir = find(strcat(dir, "*"), self);
    if (tmpdir && is_dir(tmpdir))
    {
        self = tmpdir;
    }
    else
    {
        char name[20] = "";
        printf("'%s' is not a directory\n", get_dir_name(dir, name));
    }
    return self;
}

/**
 * 查找命令
 */
int search_command(char *command)
{

    int size = sizeof(commands_list) / sizeof(char[10]);
    for (int i = 0; i < size; i++)
    {
        if (strcmp(command, commands_list[i]) == 0)
            return i;
    }
    return -1;
}

/**
 * 删除文件或文件夹
 */
void rm_dir_file(char name[20], entry self)
{
    entry tmp = find(name, self);

    if (tmp)
    {
        delete_dir_file(tmp,self);
        return;
    }
    else if (tmp = find(strcat(name, "*"), self))
    {
        delete_dir_file(tmp,self);
    }
    else
    {
        printf("'%s' is not a directory or file\n",name);
    }
}

/**
 * 执行命令
 */
entry command_exe(char *command, char arg[20], entry self)
{
    int i = search_command(command);
    switch (i)
    {
    case 0:
        insert_dir_file(make_dir_file(arg, true, self), self);
        break;
    case 1:
        self = cd_dir(arg, self);
        break;
    case 2:
        list_dir(self, 0);
        break;
    case 3:
        insert_dir_file(make_dir_file(arg, false, self), self);
        break;
    case 4:
        ls_dir(self);
        break;
    case 5:
        printf("Bye...\n");
        break;
    case 6:
        rm_dir_file(arg, self);
        break;
    default:
        printf("not found command : '%s'\n", command);
        break;
    }

    return self;
}

/**
 * 指令处理
 */
int command_handle(char command_line[], char *ins, char arg[][20])
{
    char delim[2] = " ";
    char *token = NULL;
    int counter = 0;

    /* 获取第一个子字符串 */
    token = strtok(command_line, delim);
    if (!token)
    {
        ins = "";
        return 0;
    }
    strcpy(ins, token);
    /* 继续获取其他的子字符串 */
    while (token = strtok(NULL, delim))
    {
        strcpy(arg[counter++], token);
    }

    return counter + 1;
}

void welcome_info()
{
    printf("|---------------------------------------------------------|\n");
    printf("|# Simulate File System                                   |\n");
    printf("|# support list of commands :                             |\n");
    printf("|# ['mkdir' 'cd', 'tree', 'tuch', 'ls', 'exit', 'rm']     |\n");
    printf("|# Version:1.01, 20th, Otc,2019                           |\n");
    printf("|---------------------------------------------------------|\n");
}

int main(void)
{
    char name[20] = "root";
    Tree root = make_dir_file(name, true,NULL);
    entry self = root;
    char ins_line[30] = "";
    char ins[10] = "";
    char args[5][20];

    welcome_info();
    while (strcmp(ins, "exit"))
    {
        commands_line(self, "Host");
        gets(ins_line);
        if (command_handle(ins_line, ins, args))
            self = command_exe(ins, args[0], self);
    }

    return 0;
}