#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <stdlib.h>

extern size_t ft_strlen(const char *a);
extern char * ft_strdup(const char *a);
extern char * ft_strcpy(const char *a, const char *b);
extern int    ft_strcmp(const char *a, const char *b);

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
    assert(strcmp(strcpy(a, ""), strcpy(b, "")) == 0);
    assert(strlen(a) == 0);
    assert(strcmp(strcpy(a, "foo"), strcpy(b, "foo")) == 0);
    assert(strlen(a) == 3);
}

void test_strdup()
{
    char * s = "";
    char * a = strdup(s);
    char * b = ft_strdup(s);
    assert(a == b);
    free(a);
    free(b);
}

void test_read() {}
void test_write() {}

int main() {

    // test_strlen();
    // test_strcmp();
    // test_strcpy();
    // test_strdup();
    // test_read();
    // test_write();

    return 0;
}
