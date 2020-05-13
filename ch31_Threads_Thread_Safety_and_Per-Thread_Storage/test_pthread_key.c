#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <pthread.h>
struct stRoutineSpecificData_t {
    int idx;
};
static pthread_once_t _routine_once_stRoutineSpecificData_t = 0; 
static pthread_key_t _routine_key_stRoutineSpecificData_t;
static int _routine_init_stRoutineSpecificData_t = 0;
static void _routine_make_key_stRoutineSpecificData_t() { 
    (void) pthread_key_create(&_routine_key_stRoutineSpecificData_t, __null); 
}
template <class T>
class clsRoutineData_routine_stRoutineSpecificData_t{
    public: 
        inline T *operator->() { 
            if( !_routine_init_stRoutineSpecificData_t ) { 
                pthread_once( &_routine_once_stRoutineSpecificData_t,_routine_make_key_stRoutineSpecificData_t ); 
                _routine_init_stRoutineSpecificData_t = 1; 
            } 
            T* p = (T*)pthread_getspecific( _routine_key_stRoutineSpecificData_t ); 
            if( !p ) { 
                p = (T*)calloc(1,sizeof( T )); 
                int ret = pthread_setspecific( _routine_key_stRoutineSpecificData_t,p) ; 
                if ( ret ) { 
                    if ( p ) { 
                        free(p); 
                        p = __null; 
                    } 
                } 
            } 
            return p; 
        }
};
static clsRoutineData_routine_stRoutineSpecificData_t<stRoutineSpecificData_t> __routine;
static clsRoutineData_routine_stRoutineSpecificData_t<stRoutineSpecificData_t> __routine1;
#include <stdint.h>
static inline unsigned long long get_tick_count()
{
    uint32_t lo, hi;
    __asm__ __volatile__ (
            "rdtscp" : "=a"(lo), "=d"(hi)
            );
    return ((unsigned long long)lo) | (((unsigned long long)hi) << 32);
}

void *
threadFunc1(void *arg)
{
    int *s = (int *) arg;

    printf("111\t%d\n", *s);
    __routine->idx = *s;
    printf("1111\t%d\n", __routine1->idx);

}
void *
threadFunc2(void *arg)
{
    int *s = (int *) arg;
    sleep(10);
    printf("222\t%d\n", *s);
    printf("222\t%d\n",__routine->idx);
}


static pthread_key_t strerrorKey1;
static pthread_key_t strerrorKey2;
static void func1() { 
    (void) pthread_key_create(&strerrorKey1, __null); 
}
static void func2() { 
    (void) pthread_key_create(&strerrorKey2, __null); 
}

int main() {
    pthread_t t1;
    pthread_t t2;
    int s1 = 123;
    int s2 = 456;
    printf("t1:1\n");
static pthread_once_t _routine_once_stRoutineSpecificData_t1 = 0; 
static pthread_once_t _routine_once_stRoutineSpecificData_t2 = 0; 
pthread_once( &_routine_once_stRoutineSpecificData_t1, func1); 
pthread_once( &_routine_once_stRoutineSpecificData_t1, func2); 
    printf("%d\n", strerrorKey1);
    printf("%d\n", strerrorKey2);return 0;
    //printf("t1:%lu\n", get_tick_count());
    printf("t1:2\n");
    int p1 = pthread_create(&t1, NULL, threadFunc1, &s1);
    int p2 = pthread_create(&t2, NULL, threadFunc2, &s2);
    pthread_join(t1, NULL);
    pthread_join(t2, NULL);
    //printf("t2:%lu\n", get_tick_count());
    return 0;




}



