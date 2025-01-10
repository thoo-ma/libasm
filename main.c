#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>
#include <errno.h>
#include <stddef.h>

extern size_t  ft_strlen(const char *a) __attribute__((nonnull(1)));
extern char *  ft_strdup(const char *a) __attribute__((nonnull(1)));
extern char *  ft_strcpy(const char *a, const char *b) __attribute__((nonnull(1, 2)));
extern int     ft_strcmp(const char *a, const char *b) __attribute__((nonnull(1, 2)));
extern ssize_t ft_read(int fd, void *buf, size_t count);
extern ssize_t ft_write(int fd, const void *buf, size_t count);   

void test_strlen()
{
    assert(strlen("") == ft_strlen(""));
    assert(strlen("foo") == ft_strlen("foo"));
    assert(strlen("foo\0bar") == ft_strlen("foo\0bar"));
}

void test_strcmp()
{
    assert(strcmp("", "") == ft_strcmp("", ""));
    assert(strcmp("", "foo") == ft_strcmp("", "foo"));
    assert(strcmp("foo", "") == ft_strcmp("foo", ""));
    assert(strcmp("foo", "foo") == ft_strcmp("foo", "foo"));
    assert(strcmp("foo", "foobar") == ft_strcmp("foo", "foobar"));
    assert(strcmp("foobar", "foo") == ft_strcmp("foobar", "foo"));
}

void test_strcpy()
{
    char a[42] = "42";
    char b[42] = "42";

    assert(strcmp(strcpy(a, ""), ft_strcpy(b, "")) == 0);
    assert(strlen(a) == 0);
    assert(strlen(b) == 0);

    assert(strcmp(strcpy(a, "foobar"), ft_strcpy(b, "foobar")) == 0);
    assert(strlen(a) == 6);
    assert(strlen(b) == 6);

    assert(strcmp(strcpy(a, "foo\0bar"), ft_strcpy(b, "foo\0bar")) == 0);
    assert(strlen(a) == 3);
    assert(strlen(b) == 3);
}

void test_strdup()
{
    char * s = "foobar";
    char * a = strdup(s);
    char * b = ft_strdup(s);

    assert(strcmp(a, s) == 0);
    assert(strcmp(b, s) == 0);

    free(a);
    free(b);

    char * x = "";
    char * c = strdup(x);
    char * d = ft_strdup(x);

    assert(strcmp(c, x) == 0);
    assert(strcmp(d, x) == 0);

    free(c);
    free(d);
}

void test_read_file(char * file)
{
    char a[42];
    char b[42];

    int fd = open(file, O_RDONLY);
    if (fd < 0) {
        perror("open");
        return;
    }

    ssize_t x = read(fd, a, 42);

    if (lseek(fd, 0, SEEK_SET) < 0) {
        perror("lseek");
        close(fd);
        return;
    }

    ssize_t y = ft_read(fd, b, 42);

    assert(x == y);
    assert(strcmp(a, b) == 0);
}

void test_read_stdin()
{
    char a[42];
    char b[42];
    ssize_t x = read(0, a, 42);
    ssize_t y = ft_read(0, b, 42);
    assert(x == y);
}

void test_read_error()
{
    // testig only one error case: fd do not exist

    char a[42];
    char b[42];

    int ft_errno;
    int std_errno;

    char * ft_strerror;
    char * std_strerror;

    ssize_t x = read(42, a, 42);
    if (x < 0) {
        std_errno = errno;
        std_strerror = strerror(errno);
    }

    ssize_t y = ft_read(42, b, 42);
    if (y < 0) {
        ft_errno = errno;
        ft_strerror = strerror(errno);
    }

    assert(x == y);
    assert(ft_errno == std_errno);
    assert(strcmp(ft_strerror, std_strerror) == 0);
}

void test_read()
{
    test_read_file("input/empty.txt");
    test_read_file("input/lorem.txt");
    test_read_stdin();
    test_read_error();
}

void test_write_stdout()
{
    char * s = "foo\n";
    ssize_t x, y;

    x = write(1, s, 4);
    y = ft_write(1, s, 4);
    assert(x == y);

    x = write(1, s, 2);
    y = ft_write(1, s, 2);
    assert(x == y);
}

void test_write_error()
{
    // testig only one error case: fd do not exist

    char * s = "foo\n";
    char * ft_strerror;
    char * std_strerror;
    int ft_errno;
    int std_errno;
    ssize_t x, y;

    x = write(42, s, 2);
    if (x < 0) {
        std_errno = errno;
        std_strerror = strerror(errno);
    }

    y = ft_write(42, s, 2);
    if (y < 0) {
        ft_errno = errno;
        ft_strerror = strerror(errno);
    }

    assert(x == y);
    assert(ft_errno == std_errno);
    assert(strcmp(ft_strerror, std_strerror) == 0);
}

void test_write()
{
    test_write_stdout();
    test_write_error();
}

int main() {
    test_strlen();
    test_strcmp();
    test_strcpy();
    test_strdup();
    test_read();
    test_write();
    return 0;
}
