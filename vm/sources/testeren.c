#include "../includes/corewar.h"
void memrev(char  *buf, size_t count)
{
    char *r;
    for (r = buf + count - 1; buf < r; buf++, r--)
    {
        *buf ^= *r;
        *r   ^= *buf;
        *buf ^= *r;
    }
}
int main(int argc, char **argv)
{
    int fd;
    int ret;
    bin_t plr;
    int i;
    char *buff;
    unsigned int num = 2130706432;
    i = 0;
    plr.magic = 0;
    plr.prog_size = 0;
    if ((fd = open(argv[1], O_RDONLY)) == -1)
        printf("error\n");
    buff = malloc(sizeof(char) * 4 + 1);
    ret = read(fd, buff, 4);
    buff[ret] = '\0';
    // memrev(buff, 4);
    buff[0] = (num>>24) & 0xFF;
    buff[1] = (num>>16) & 0xFF;
    buff[2] = (num>>8) & 0xFF;
    buff[3] = num & 0xFF;
    plr.magic = *(int *)buff;
    // plr.magic = (unsigned int)buff;
    putchar('\n');
    while (i  < 4)
    {
        printf("|%x|", buff[i]);
        i++;
    }
    i = 0;
    printf("\n%u\n", plr.magic);
    ret = read(fd, plr.prog_name, PROG_NAME_LENGTH + 4);
    plr.prog_name[ret] = '\0';
    while (plr.prog_name[i])
    {
        printf("%x", plr.prog_name[i]);
        i++;
    }
    putchar('\n');
    i = 0;
    // buff = malloc(sizeof(char) * 4 + 1);
    ret = read(fd, buff, 4);
    buff[ret] = '\0';
    plr.prog_size = buff[0] + buff[1] * 256 + buff[2] * 256 * 256 + buff[3] * 256 * 256 * 256;
    printf("\n%u\n", plr.prog_size);
    while (i < 4)
    {
        printf("[%x]", buff[i]);
        i++;
    }
    i = 0;
    ret = read(fd, plr.comment, COMMENT_LENGTH);
    plr.comment[ret] = '\0';
    putchar('\n');
    while (i < COMMENT_LENGTH)
    {
        printf("%x", plr.comment[i]);
        i++;
    }
    putchar('\n');
    i = 0;
    ret = read(fd, plr.program, CHAMP_MAX_SIZE);
    plr.program[ret] = '\0';
    while (i < CHAMP_MAX_SIZE)
    {
        printf("%x", plr.program[i]);
        i++;
    }
    i = 0;
    putchar('\n');
    return (0);
