#include <stdio.h>
#include <pthread.h>
static pthread_key_t strerrorKey1;
static pthread_key_t strerrorKey2;
static pthread_key_t strerrorKey3;
static pthread_key_t strerrorKey4;
int main() {
    int s = pthread_key_create(&strerrorKey1, NULL);
    int s2 = pthread_key_create(&strerrorKey2, NULL);
    int s3 = pthread_key_create(&strerrorKey3, NULL);
    int s4 = pthread_key_create(&strerrorKey4, NULL);
    printf("%d\n%d\n%d\n%d\n", strerrorKey1, strerrorKey2, strerrorKey3, strerrorKey4);
    return 0;
}
