#ifndef AK_BASE_H
#define AK_BASE_H

#include <stdint.h>
#include <stdlib.h>
#include <math.h>

#ifdef _MSC_VER
#define AK_COMPILER_MSVC
#else
#error Not Implemented
#endif

#ifdef _WIN32
#define AK_OS_WIN32
#else
#error Not Implemented
#endif

#define AK_Glue_(a, b) a##b
#define AK_Glue(a, b) AK_Glue_(a, b)

#define AK_Stringify_(a) #a
#define AK_Stringify(a) AK_Stringify_(a)

#define AK_Kilo(x) ((x)*1024LL)
#define AK_Mega(x) (AK_Kilo(x)*1024LL)
#define AK_Giga(x) (AK_Mega(x)*1024LL)
#define AK_Tera(x) (AK_Giga(x)*1024LL)

#define AK_LINE_NUMBER __LINE__
#define AK_FUNCTION_NAME __FUNCSIG__
#define AK_FILENAME __FILE__

#if defined(AK_COMPILER_MSVC)
#define ak_threadvar __declspec(thread)
#define ak_shared_export __declspec(dllexport)
#define AK_Write_Barrier() _WriteBarrier()
#define AK_Read_Barrier() _ReadBarrier()
#define AK_Read_Write_Barrier() _ReadWriteBarrier()
#else
#error Not Implemented
#endif

#ifdef AK_OS_WIN32
#define AK_Debug_Break() __debugbreak();
#else
#error Not Implemented
#endif

#ifndef AK_Assert
#define AK_Assert(c) do { if(!(c)) AK_Debug_Break(); } while(0)
#endif

#ifndef AK_Static_Assert
#define AK_Static_Assert(c) char AK_Glue(__Ignore__Value__, AK_LINE_NUMBER)[(c) ? 1 : -1]
#endif

#define AK_Not_Implemented() AK_Assert(!"Not Implemented")
#define AK_Invalid_Default_Case() default: { AK_Not_Implemented(); } break

#define AK_Array_Count(array) ((sizeof(array))/sizeof(*array))
#define AK_Array_Expand(array) (array), (AK_Array_Count(Array))
#define AK_Ptr_Diff(a, b) ((uint8_t*)(a) - (uint8_t*)(b))
#define AK_Ptr_To_Int(a) AK_Ptr_Diff(a, 0)
#define AK_Int_To_Ptr(a) (void*)(((uint8_t*)0)+a)
#define AK_Ptr_To_U64(a) (uint64_t)(AK_Ptr_To_Int(a))
#define AK_Member(T, m) (((T*)0)->m)
#define AK_Member_Offset(T, m) AK_Ptr_To_Int(&AK_Member(T, m))

#define AK_Swap(a, b) do \
{ \
auto AK_Glue(Hidden_Swap_, AK_LINE_NUMBER) = a; \
a = b; \
b = AK_Glue(Hidden_Swap_, AK_LINE_NUMBER); \
} while(0)

#define AK_Min(a, b) (((a)>(b))?(a):(b))
#define AK_Max(a, b) (((a)<(b))?(a):(b))
#define AK_Abs(x) ((x) < 0 ? -(x) : (x))
#define AK_Clamp(Min, X, Max) ((V < Min) ? Min : ((V > Max) ? Max : V))
#define AK_Saturate(V) AK_Clamp(0.0f, V, 1.0f)
#define AK_Lerp(A, t, B) ((A) + (t)*((B)-(A)))

#define AK_Is_Aligned(pointer, alignment) (((size_t)(const void*)(pointer)) % (alignment) == 0)

typedef int8_t bool8_t;
typedef int16_t bool16_t;
typedef int32_t bool32_t;
typedef int64_t bool64_t;

#ifdef AK_OS_WIN32
#include <windows.h>
typedef HANDLE ak_thread;
typedef CRITICAL_SECTION ak_mutex;
typedef HANDLE ak_semaphore;
typedef HANDLE ak_event;
typedef HANDLE ak_file;
#else
#error Not Implemented
#endif

#ifdef AK_COMPILER_MSVC
#include <intrin.h>
#else
#endif

static const uint32_t AK_Bit_1  = 0x00000001;
static const uint32_t AK_Bit_2  = 0x00000002;
static const uint32_t AK_Bit_3  = 0x00000004;
static const uint32_t AK_Bit_4  = 0x00000008;
static const uint32_t AK_Bit_5  = 0x00000010;
static const uint32_t AK_Bit_6  = 0x00000020;
static const uint32_t AK_Bit_7  = 0x00000040;
static const uint32_t AK_Bit_8  = 0x00000080;
static const uint32_t AK_Bit_9  = 0x00000100;
static const uint32_t AK_Bit_10 = 0x00000200;
static const uint32_t AK_Bit_11 = 0x00000400;
static const uint32_t AK_Bit_12 = 0x00000800;
static const uint32_t AK_Bit_13 = 0x00001000;
static const uint32_t AK_Bit_14 = 0x00002000;
static const uint32_t AK_Bit_15 = 0x00004000;
static const uint32_t AK_Bit_16 = 0x00008000;
static const uint32_t AK_Bit_17 = 0x00010000;
static const uint32_t AK_Bit_18 = 0x00020000;
static const uint32_t AK_Bit_19 = 0x00040000;
static const uint32_t AK_Bit_20 = 0x00080000;
static const uint32_t AK_Bit_21 = 0x00100000;
static const uint32_t AK_Bit_22 = 0x00200000;
static const uint32_t AK_Bit_23 = 0x00400000;
static const uint32_t AK_Bit_24 = 0x00800000;
static const uint32_t AK_Bit_25 = 0x01000000;
static const uint32_t AK_Bit_26 = 0x02000000;
static const uint32_t AK_Bit_27 = 0x04000000;
static const uint32_t AK_Bit_28 = 0x08000000;
static const uint32_t AK_Bit_29 = 0x10000000;
static const uint32_t AK_Bit_30 = 0x20000000;
static const uint32_t AK_Bit_31 = 0x40000000;
static const uint32_t AK_Bit_32 = 0x80000000;

static const uint64_t AK_Bit_33 = 0x0000000100000000;
static const uint64_t AK_Bit_34 = 0x0000000200000000;
static const uint64_t AK_Bit_35 = 0x0000000400000000;
static const uint64_t AK_Bit_36 = 0x0000000800000000;
static const uint64_t AK_Bit_37 = 0x0000001000000000;
static const uint64_t AK_Bit_38 = 0x0000002000000000;
static const uint64_t AK_Bit_39 = 0x0000004000000000;
static const uint64_t AK_Bit_40 = 0x0000008000000000;
static const uint64_t AK_Bit_41 = 0x0000010000000000;
static const uint64_t AK_Bit_42 = 0x0000020000000000;
static const uint64_t AK_Bit_43 = 0x0000040000000000;
static const uint64_t AK_Bit_44 = 0x0000080000000000;
static const uint64_t AK_Bit_45 = 0x0000100000000000;
static const uint64_t AK_Bit_46 = 0x0000200000000000;
static const uint64_t AK_Bit_47 = 0x0000400000000000;
static const uint64_t AK_Bit_48 = 0x0000800000000000;
static const uint64_t AK_Bit_49 = 0x0001000000000000;
static const uint64_t AK_Bit_50 = 0x0002000000000000;
static const uint64_t AK_Bit_51 = 0x0004000000000000;
static const uint64_t AK_Bit_52 = 0x0008000000000000;
static const uint64_t AK_Bit_53 = 0x0010000000000000;
static const uint64_t AK_Bit_54 = 0x0020000000000000;
static const uint64_t AK_Bit_55 = 0x0040000000000000;
static const uint64_t AK_Bit_56 = 0x0080000000000000;
static const uint64_t AK_Bit_57 = 0x0100000000000000;
static const uint64_t AK_Bit_58 = 0x0200000000000000;
static const uint64_t AK_Bit_59 = 0x0400000000000000;
static const uint64_t AK_Bit_60 = 0x0800000000000000;
static const uint64_t AK_Bit_61 = 0x1000000000000000;
static const uint64_t AK_Bit_62 = 0x2000000000000000;
static const uint64_t AK_Bit_63 = 0x4000000000000000;
static const uint64_t AK_Bit_64 = 0x8000000000000000;

static const uint32_t AK_Bitmask_1  = 0x00000001;
static const uint32_t AK_Bitmask_2  = 0x00000003;
static const uint32_t AK_Bitmask_3  = 0x00000007;
static const uint32_t AK_Bitmask_4  = 0x0000000f;
static const uint32_t AK_Bitmask_5  = 0x0000001f;
static const uint32_t AK_Bitmask_6  = 0x0000003f;
static const uint32_t AK_Bitmask_7  = 0x0000007f;
static const uint32_t AK_Bitmask_8  = 0x000000ff;
static const uint32_t AK_Bitmask_9  = 0x000001ff;
static const uint32_t AK_Bitmask_10 = 0x000003ff;
static const uint32_t AK_Bitmask_11 = 0x000007ff;
static const uint32_t AK_Bitmask_12 = 0x00000fff;
static const uint32_t AK_Bitmask_13 = 0x00001fff;
static const uint32_t AK_Bitmask_14 = 0x00003fff;
static const uint32_t AK_Bitmask_15 = 0x00007fff;
static const uint32_t AK_Bitmask_16 = 0x0000ffff;
static const uint32_t AK_Bitmask_17 = 0x0001ffff;
static const uint32_t AK_Bitmask_18 = 0x0003ffff;
static const uint32_t AK_Bitmask_19 = 0x0007ffff;
static const uint32_t AK_Bitmask_20 = 0x000fffff;
static const uint32_t AK_Bitmask_21 = 0x001fffff;
static const uint32_t AK_Bitmask_22 = 0x003fffff;
static const uint32_t AK_Bitmask_23 = 0x007fffff;
static const uint32_t AK_Bitmask_24 = 0x00ffffff;
static const uint32_t AK_Bitmask_25 = 0x01ffffff;
static const uint32_t AK_Bitmask_26 = 0x03ffffff;
static const uint32_t AK_Bitmask_27 = 0x07ffffff;
static const uint32_t AK_Bitmask_28 = 0x0fffffff;
static const uint32_t AK_Bitmask_29 = 0x1fffffff;
static const uint32_t AK_Bitmask_30 = 0x3fffffff;
static const uint32_t AK_Bitmask_31 = 0x7fffffff;

static const uint64_t AK_Bitmask_32 = 0x00000000ffffffff;
static const uint64_t AK_Bitmask_33 = 0x00000001ffffffff;
static const uint64_t AK_Bitmask_34 = 0x00000003ffffffff;
static const uint64_t AK_Bitmask_35 = 0x00000007ffffffff;
static const uint64_t AK_Bitmask_36 = 0x0000000fffffffff;
static const uint64_t AK_Bitmask_37 = 0x0000001fffffffff;
static const uint64_t AK_Bitmask_38 = 0x0000003fffffffff;
static const uint64_t AK_Bitmask_39 = 0x0000007fffffffff;
static const uint64_t AK_Bitmask_40 = 0x000000ffffffffff;
static const uint64_t AK_Bitmask_41 = 0x000001ffffffffff;
static const uint64_t AK_Bitmask_42 = 0x000003ffffffffff;
static const uint64_t AK_Bitmask_43 = 0x000007ffffffffff;
static const uint64_t AK_Bitmask_44 = 0x00000fffffffffff;
static const uint64_t AK_Bitmask_45 = 0x00001fffffffffff;
static const uint64_t AK_Bitmask_46 = 0x00003fffffffffff;
static const uint64_t AK_Bitmask_47 = 0x00007fffffffffff;
static const uint64_t AK_Bitmask_48 = 0x0000ffffffffffff;
static const uint64_t AK_Bitmask_49 = 0x0001ffffffffffff;
static const uint64_t AK_Bitmask_50 = 0x0003ffffffffffff;
static const uint64_t AK_Bitmask_51 = 0x0007ffffffffffff;
static const uint64_t AK_Bitmask_52 = 0x000fffffffffffff;
static const uint64_t AK_Bitmask_53 = 0x001fffffffffffff;
static const uint64_t AK_Bitmask_54 = 0x003fffffffffffff;
static const uint64_t AK_Bitmask_55 = 0x007fffffffffffff;
static const uint64_t AK_Bitmask_56 = 0x00ffffffffffffff;
static const uint64_t AK_Bitmask_57 = 0x01ffffffffffffff;
static const uint64_t AK_Bitmask_58 = 0x03ffffffffffffff;
static const uint64_t AK_Bitmask_59 = 0x07ffffffffffffff;
static const uint64_t AK_Bitmask_60 = 0x0fffffffffffffff;
static const uint64_t AK_Bitmask_61 = 0x1fffffffffffffff;
static const uint64_t AK_Bitmask_62 = 0x3fffffffffffffff;
static const uint64_t AK_Bitmask_63 = 0x7fffffffffffffff;

static const uint8_t  AK_MaxU8 = 0xFF;
static const uint16_t AK_MaxU16 = 0xFFFF;
static const uint32_t AK_MaxU32 = 0xFFFFFFFF;
static const uint64_t AK_MAxU64 = 0xFFFFFFFFFFFFFFFF;

static const int8_t  AK_MaxS8 = 127;
static const int16_t AK_MaxS16 = 32767;
static const int32_t AK_MaxS32 = 2147483647;
static const int64_t AK_MaxS64 = 9223372036854775807;

static const int8_t  AK_MinS8   = -127 - 1;
static const int16_t AK_MinS16 = -32767 - 1;
static const int32_t AK_MinS32 = -2147483647 - 1;
static const int64_t AK_MinS64 = -9223372036854775807 - 1;

static const float AK_MaxF32 = 3.402823466e+38f;
static const float AK_MinF32 = -AK_MaxF32;
static const float AK_Smallest_PositiveF32 = 1.1754943508e-38f;
static const float AK_EpsilonF32 = 5.96046448e-8f;
static const float AK_PiF32 = 3.14159265359f;
static const float AK_TauF32 = 6.28318530718f;
static const float AK_ExpF32 = 2.71828182846f;
static const float AK_InfinityF32 = (float)0x7F800000;

static const double AK_MaxF64 = 1.79769313486231e+308;
static const double AK_MinF64 = -AK_MaxF64;
static const double AK_Smallest_PositiveF64 = 4.94065645841247e-324;
static const double AK_EpsilonF64 = 1.11022302462515650e-16;
static const double AK_PiF64 = 3.14159265359;
static const double AK_TauF64 = 6.28318530718;
static const double AK_ExpF64 = 2.71828182846;
static const double AK_InfinityF64 = (float)0x7FF0000000000000;

#define AK_SLL_Stack_Push_NP(head, entry, next) (entry)->next = (head); (head) = entry
#define AK_SLL_Stack_Pop_NP(head, next) (head)=(head)->next
#define AK_SLL_Queue_Push_NP(first, last, entry, next) ((first) ? (last)->next = (entry) : (first) = (last) = (entry))
#define AK_SLL_Queue_Pop_NP(first, last, next) (((first) == (last)) ? (first) = (last) = NULL : (first) = (first)->next)

#define AK_SLL_Stack_Push(head, entry) AK_SLL_Stack_Push_NP(head, entry, Next)
#define AK_SLL_Stack_Pop(head) AK_SLL_Stack_Pop_NP(head, Next)
#define AK_SLL_Queue_Push(first, last, entry) AK_SLL_Queue_Push_NP(first, last, entry, Next)
#define AK_SLL_Queue_Pop(first, last) AK_SLL_Queue_Pop_NP(first, last, Next)

#define AK_THREAD_CALLBACK(name) int name(void* UserData)
typedef AK_THREAD_CALLBACK(ak_thread_callback);

void AK_Memory_Clear(void* Dst, size_t Size);
void AK_Memory_Copy(void* Dst, const void* Src, size_t Size);
uint64_t AK_Align(uint64_t Value, uint64_t Alignment);
int64_t  AK_Align(int64_t Value,  int64_t Alignment);
uint64_t AK_Ceil_Pow2(uint64_t V);
int64_t  AK_Ceil_Pow2(int64_t V);
bool8_t AK_Equal_Zero_Approx(float V,  float Eps);
bool8_t AK_Equal_Zero_Approx(double V, double Eps);
bool8_t AK_Equal_Approx(float A, float B, float Eps);
bool8_t AK_Equal_Approx(double A, double B, double Eps);
bool8_t AK_Equal_Zero_Eps(float V);
bool8_t AK_Equal_Zero_Eps(double V);
bool8_t AK_Equal_Eps(float A, float B);
bool8_t AK_Equal_Eps(double A, double B);
float AK_Safe_Ratio(float A, float B);
double AK_Safe_Ratio(double A, double B);
float AK_Safe_RatioF32(int32_t A, int32_t B);
double AK_Safe_RatioF64(int32_t A, int32_t B);
uint8_t AK_SafeU8(uint16_t V);
uint8_t AK_SafeU8(uint32_t V);
uint8_t AK_SafeU8(uint64_t V);
uint8_t AK_SafeU8(int8_t V);
uint8_t AK_SafeU8(int16_t V);
uint8_t AK_SafeU8(int32_t V);
uint8_t AK_SafeU8(int64_t V);
uint8_t AK_SafeU8(float V);
uint8_t AK_SafeU8(double V);
uint16_t AK_SafeU16(uint32_t V);
uint16_t AK_SafeU16(uint64_t V);
uint16_t AK_SafeU16(int8_t V);
uint16_t AK_SafeU16(int16_t V);
uint16_t AK_SafeU16(int32_t V);
uint16_t AK_SafeU16(int64_t V);
uint16_t AK_SafeU16(float V);
uint16_t AK_SafeU16(double V);
uint32_t AK_SafeU32(uint64_t V);
uint32_t AK_SafeU32(int8_t V);
uint32_t AK_SafeU32(int16_t V);
uint32_t AK_SafeU32(int32_t V);
uint32_t AK_SafeU32(int64_t V);
uint32_t AK_SafeU32(float V);
uint32_t AK_SafeU32(double V);
uint64_t AK_SafeU64(int8_t V);
uint64_t AK_SafeU64(int16_t V);
uint64_t AK_SafeU64(int32_t V);
uint64_t AK_SafeU64(int64_t V);
uint64_t AK_SafeU64(float V);
uint64_t AK_SafeU64(double V);
int8_t AK_SafeS8(uint8_t V);
int8_t AK_SafeS8(uint16_t V);
int8_t AK_SafeS8(uint32_t V);
int8_t AK_SafeS8(uint64_t V);
int8_t AK_SafeS8(int16_t V);
int8_t AK_SafeS8(int32_t V);
int8_t AK_SafeS8(int64_t V);
int16_t AK_SafeS16(uint16_t V);
int16_t AK_SafeS16(uint32_t V);
int16_t AK_SafeS16(uint64_t V);
int16_t AK_SafeS16(int32_t V);
int16_t AK_SafeS16(int64_t V);
int32_t AK_SafeS32(uint32_t V);
int32_t AK_SafeS32(uint64_t V);
int32_t AK_SafeS32(int64_t V);
int64_t AK_SafeS64(uint64_t V);
float  AK_Sqrt(float V);
double AK_Sqrt(double V);
float  AK_Sin(float V);
double AK_Sin(double B);
float  AK_Cos(float V);
double AK_Cos(double B);
float  AK_Tan(float V);
double AK_Tan(double B);
float  AK_ASin(float V);
double AK_ASin(double B);
float  AK_ACos(float V);
double AK_ACos(double B);
float  AK_ATan(float V);
double AK_ATan(double B);
float  AK_ATan2(float Y, float X);
double AK_ATan2(double Y, double X);
float  AK_Pow(float V, float Exp); 
double AK_Pow(double V, double Exp);
float  AK_Floor(float V);
double AK_Floor(double V);
float  AK_Ceil(float V);
double AK_Ceil(double V);
float  AK_Round(float V);
double AK_Round(double V);
char     AK_To_Upper(char C);
uint8_t  AK_To_Upper(uint8_t C);
uint16_t AK_To_Upper(uint16_t C);
uint32_t AK_To_Upper(uint32_t C);
char     AK_To_Lower(char C);
uint8_t  AK_To_Lower(uint8_t C);
uint16_t AK_To_Lower(uint16_t C);
uint32_t AK_To_Lower(uint32_t C);
int32_t AK_Atomic_Increment32(volatile int32_t* Addend);
int64_t AK_Atomic_Increment64(volatile int64_t* Addend);
int32_t AK_Atomic_Decrement32(volatile int32_t* Addend);
int64_t AK_Atomic_Decrement64(volatile int64_t* Addend);
int32_t AK_Atomic_Add32(volatile int32_t* Addend, int32_t Value);
int64_t AK_Atomic_Add64(volatile int64_t* Addend, int64_t Value);
int32_t AK_Atomic_Exchange32(volatile int32_t* Dst, int32_t Value);
int64_t AK_Atomic_Exchange64(volatile int64_t* Dst, int64_t Value);
void*   AK_Atomic_ExchangePtr(volatile void** Dst, void* Value);
int32_t AK_Atomic_Compare_Exchange32(volatile int32_t* Dst, int32_t Exchange, int32_t Comperand);
int64_t AK_Atomic_Compare_Exchange64(volatile int64_t* Dst, int64_t Exchange, int64_t Comperand);
void*   AK_Atomic_Compare_ExchangePtr(volatile void** Dst, void* Exchange, void* Comperand);

ak_thread AK_Create_Thread(ak_thread_callback* ThreadCallback, void* UserData);
void      AK_Wait_Thread(ak_thread Thread);
void      AK_Delete_Thread(ak_thread Thread);

ak_mutex  AK_Create_Mutex();
void      AK_Lock_Mutex(ak_mutex Mutex);
void      AK_Unlock_Mutex(ak_mutex Mutex);
void      AK_Delete_Mutex(ak_mutex Mutex);

ak_semaphore AK_Create_Semaphore(uint32_t InitialCount);
void         AK_Decrement_Semaphore(ak_semaphore Semaphore);
void         AK_Increment_Semaphore(ak_semaphore Semaphore);
void         AK_Delete_Semaphore(ak_semaphore Semaphore);

ak_event AK_Create_Event();
void     AK_Wait_Event(ak_event Event);
void     AK_Signal_Event(ak_event Event);
void     AK_Delete_Event(ak_event Event);

struct ak_spin_lock
{
    volatile int64_t Target;
    volatile int64_t Current;
    
    void Lock();
    void Unlock();
};

enum ak_clear_flag
{
    AK_CLEAR,
    AK_NO_CLEAR
};

struct ak_allocator;

#define AK_ALLOCATE_MEMORY(name) void* name(ak_allocator* Allocator, size_t Size, size_t Alignment, ak_clear_flag ClearFlag)
typedef AK_ALLOCATE_MEMORY(ak_allocate_memory);

#define AK_FREE_MEMORY(name) void name(ak_allocator* Allocator, void* Memory)
typedef AK_FREE_MEMORY(ak_free_memory);

struct ak_allocator
{
    ak_allocate_memory* Allocate;
    ak_free_memory*     Free;
};

struct ak_async_allocator : public ak_allocator
{
    ak_spin_lock Lock;
};

ak_async_allocator* AK_Get_Default_Allocator();

struct ak__arena_block;
struct ak_arena;

struct ak_arena_marker
{
    ak_arena* Arena;
    ak__arena_block* Block;
    size_t    Marker;
};

struct ak_arena : public ak_allocator
{
    ak_allocator*    Allocator;
    ak__arena_block* FirstBlock;
    ak__arena_block* CurrentBlock;
    ak__arena_block* LastBlock;
    size_t           InitialBlockSize;
    
    void* Push(size_t Size, size_t Alignment, ak_clear_flag ClearFlag = AK_CLEAR);
    void* Push(size_t Size, ak_clear_flag ClearFlag = AK_CLEAR);
    
    template <typename type> type* Push_Struct(size_t Alignment, ak_clear_flag ClearFlag = AK_CLEAR);
    template <typename type> type* Push_Struct(ak_clear_flag ClearFlag = AK_CLEAR);
    
    template <typename type> type* Push_Array(size_t Count, size_t Alignment, ak_clear_flag ClearFlag = AK_CLEAR);
    template <typename type> type* Push_Array(size_t Count, ak_clear_flag ClearFlag = AK_CLEAR);
    
    ak_arena_marker Get_Marker();
    void Set_Marker(ak_arena_marker Marker);
    void Clear(ak_clear_flag ClearFlag = AK_CLEAR);
};

struct ak_temp_arena
{
    ak_arena_marker Marker;
    ak_temp_arena(ak_arena* TempArena);
    void Begin(ak_arena* TempArena);
    void End();
    ~ak_temp_arena();
};

struct ak_async_arena : public ak_async_allocator
{
    ak_async_allocator* Allocator;
    ak__arena_block*    FirstBlock;
    ak__arena_block*    CurrentBlock;
    ak__arena_block*    LastBlock;
    size_t              InitialBlockSize;
    
    void* Push(size_t Size, size_t Alignment, ak_clear_flag ClearFlag = AK_CLEAR);
    void* Push(size_t Size, ak_clear_flag ClearFlag = AK_CLEAR);
    
    template <typename type> type* Push_Struct(size_t Alignment, ak_clear_flag ClearFlag = AK_CLEAR);
    template <typename type> type* Push_Struct(ak_clear_flag ClearFlag = AK_CLEAR);
    
    template <typename type> type* Push_Array(size_t Count, size_t Alignment, ak_clear_flag ClearFlag = AK_CLEAR);
    template <typename type> type* Push_Array(size_t Count, ak_clear_flag ClearFlag = AK_CLEAR);
    
    void Clear(ak_clear_flag ClearFlag = AK_CLEAR);
};

#endif

#ifdef AK_BASE_IMPLEMENTATION

inline void AK_Memory_Clear(void* Dst, size_t Size)
{
    memset(Dst, 0, Size);
}

inline void AK_Memory_Copy(void* Dst, const void* Src, size_t Size)
{
    memcpy(Dst, Src, Size);
}

inline uint64_t AK_Align(uint64_t Value, uint64_t Alignment)
{
    Alignment = Alignment ? Alignment : 1;
    uint64_t Mod = Value & (Alignment-1);
    return Mod ? Value + (Alignment-Mod) : Value;
}

inline int64_t AK_Align(int64_t Value, int64_t Alignment)
{
    Alignment = Alignment ? Alignment : 1;
    int64_t Mod = Value & (Alignment-1);
    return Mod ? Value + (Alignment-Mod) : Value;
}

uint64_t AK_Ceil_Pow2(uint64_t V)
{
    --V;
    V |= V >> 1;
    V |= V >> 2;
    V |= V >> 4;
    V |= V >> 8;
    V |= V >> 16;
    V |= V >> 32;
    ++V;
    V += ( V == 0 );    
    return V;
}

int64_t  AK_Ceil_Pow2(int64_t V)
{
    --V;
    V |= V >> 1;
    V |= V >> 2;
    V |= V >> 4;
    V |= V >> 8;
    V |= V >> 16;
    V |= V >> 32;
    ++V;
    V += ( V == 0 );    
    return V;
}

inline bool8_t AK_Equal_Zero_Approx(float V,  float Eps)
{
    return AK_Abs(V) < Eps;
}

inline bool8_t AK_Equal_Zero_Approx(double V, double Eps)
{
    return AK_Abs(V) < Eps;
}

inline bool8_t AK_Equal_Approx(float A, float B, float Eps)
{
    return AK_Equal_Zero_Approx(A-B, Eps);
}

inline bool8_t AK_Equal_Approx(double A, double B, double Eps)
{
    return AK_Equal_Zero_Approx(A-B, Eps);
}

inline bool8_t AK_Equal_Zero_Eps(float V)
{
    return AK_Equal_Zero_Approx(V, AK_EpsilonF32);
}

inline bool8_t AK_Equal_Zero_Eps(double V)
{
    return AK_Equal_Zero_Approx(V, AK_EpsilonF64);
}

inline bool8_t AK_Equal_Eps(float A, float B)
{
    return AK_Equal_Approx(A, B, AK_EpsilonF32);
}

inline bool8_t AK_Equal_Eps(double A, double B)
{
    return AK_Equal_Approx(A, B, AK_EpsilonF64);
}

inline float AK_Safe_Ratio(float A, float B)
{
    AK_Assert(!AK_Equal_Zero_Eps(B));
    return A/B;
}

inline double AK_Safe_Ratio(double A, double B)
{
    AK_Assert(!AK_Equal_Zero_Eps(B));
    return A/B;
}

inline float AK_Safe_RatioF32(int32_t A, int32_t B)
{
    AK_Assert(B);
    return (float)A/(float)B;
}

inline double AK_Safe_RatioF64(int32_t A, int32_t B)
{
    AK_Assert(B);
    return (double)A/(double)B;
}

inline uint8_t AK_SafeU8(uint16_t V)
{
    AK_Assert(V <= AK_MaxU8);
    return (uint8_t)V;
}

inline uint8_t AK_SafeU8(uint32_t V)
{
    AK_Assert(V <= AK_MaxU8);
    return (uint8_t)V;
}

inline uint8_t AK_SafeU8(uint64_t V)
{
    AK_Assert(V <= AK_MaxU8);
    return (uint8_t)V;
}

inline uint8_t AK_SafeU8(int8_t V)
{
    AK_Assert(V >= 0);
    return (uint8_t)V;
}

inline uint8_t AK_SafeU8(int16_t V)
{
    AK_Assert(V >= 0 && V <= AK_MaxU8);
    return (uint8_t)V;
}

inline uint8_t AK_SafeU8(int32_t V)
{
    AK_Assert(V >= 0 && V <= AK_MaxU8);
    return (uint8_t)V;
}

inline uint8_t AK_SafeU8(int64_t V)
{
    AK_Assert(V >= 0 && V <= AK_MaxU8);
    return (uint8_t)V;
}

inline uint8_t AK_SafeU8(float V)
{
    AK_Assert(V >= 0 && V <= (float)AK_MaxU8);
    return (uint8_t)V;
}

inline uint8_t AK_SafeU8(double V)
{
    AK_Assert(V >= 0 && V <= (double)AK_MaxU8);
    return (uint8_t)V;
}

inline uint16_t AK_SafeU16(uint32_t V)
{
    AK_Assert(V <= AK_MaxU16);
    return (uint16_t)V;
}

inline uint16_t AK_SafeU16(uint64_t V)
{
    AK_Assert(V <= AK_MaxU16);
    return (uint16_t)V;
}

inline uint16_t AK_SafeU16(int8_t V)
{
    AK_Assert(V >= 0);
    return (uint16_t)V;
}

inline uint16_t AK_SafeU16(int16_t V)
{
    AK_Assert(V >= 0);
    return (uint16_t)V;
}

inline uint16_t AK_SafeU16(int32_t V)
{
    AK_Assert(V >= 0 && V < AK_MaxU16);
    return (uint16_t)V;
}

inline uint16_t AK_SafeU16(int64_t V)
{
    AK_Assert(V >= 0 && V < AK_MaxU16);
    return (uint16_t)V;
}

inline uint16_t AK_SafeU16(float V)
{
    AK_Assert(V >= 0 && V <= (float)AK_MaxU16);
    return (uint8_t)V;
}

inline uint16_t AK_SafeU16(double V)
{
    AK_Assert(V >= 0 && V <= (double)AK_MaxU16);
    return (uint8_t)V;
}

inline uint32_t AK_SafeU32(uint64_t V)
{
    AK_Assert(V <= AK_MaxU32);
    return (uint32_t)V;
}

inline uint32_t AK_SafeU32(int8_t V)
{
    AK_Assert(V >= 0);
    return (uint32_t)V;
}

inline uint32_t AK_SafeU32(int16_t V)
{
    AK_Assert(V >= 0);
    return (uint32_t)V;
}

inline uint32_t AK_SafeU32(int32_t V)
{
    AK_Assert(V >= 0);
    return (uint32_t)V;
}

inline uint32_t AK_SafeU32(int64_t V)
{
    AK_Assert(V >= 0 && V <= AK_MaxU32);
    return (uint32_t)V;
}

inline uint32_t AK_SafeU32(float V)
{
    AK_Assert(V >= V && V <= (float)AK_MaxU32);
    return (uint32_t)V;
}

inline uint32_t AK_SafeU32(double V)
{
    AK_Assert(V >= V && V <= (double)AK_MaxU32);
    return (uint32_t)V;
}

inline uint64_t AK_SafeU64(int8_t V)
{
    AK_Assert(V >= 0);
    return (uint64_t)V;
}

inline uint64_t AK_SafeU64(int16_t V)
{
    AK_Assert(V >= 0);
    return (uint64_t)V;
}

inline uint64_t AK_SafeU64(int32_t V)
{
    AK_Assert(V >= 0);
    return (uint64_t)V;
}

inline uint64_t AK_SafeU64(int64_t V)
{
    AK_Assert(V >= 0);
    return (uint64_t)V;
}

inline uint64_t AK_SafeU64(float V)
{
    AK_Assert(V >= 0);
    return (uint64_t)V;
}

inline uint64_t AK_SafeU64(double V)
{
    AK_Assert(V >= 0);
    return (uint64_t)V;
}

inline int8_t AK_SafeS8(uint8_t V)
{
    AK_Assert(V <= AK_MaxS8);
    return (int8_t)V;
}

inline int8_t AK_SafeS8(uint16_t V)
{
    AK_Assert(V <= AK_MaxS8);
    return (int8_t)V;
}

inline int8_t AK_SafeS8(uint32_t V)
{
    AK_Assert(V <= AK_MaxS8);
    return (int8_t)V;
}

inline int8_t AK_SafeS8(uint64_t V)
{
    AK_Assert(V <= AK_MaxS8);
    return (int8_t)V;
}

inline int8_t AK_SafeS8(int16_t V)
{
    AK_Assert(V >= AK_MinS8 && V <= AK_MaxS8);
    return (int8_t)V;
}

inline int8_t AK_SafeS8(int32_t V)
{
    AK_Assert(V >= AK_MinS8 && V <= AK_MaxS8);
    return (int8_t)V;
}

inline int8_t AK_SafeS8(int64_t V)
{
    AK_Assert(V >= AK_MinS8 && V <= AK_MaxS8);
    return (int8_t)V;
}

inline int16_t AK_SafeS16(uint16_t V)
{
    AK_Assert(V <= AK_MaxS16);
    return (int16_t)V;
}

inline int16_t AK_SafeS16(uint32_t V)
{
    AK_Assert(V <= AK_MaxS16);
    return (int16_t)V;
}

inline int16_t AK_SafeS16(uint64_t V)
{
    AK_Assert(V <= AK_MaxS16);
    return (int16_t)V;
}

inline int16_t AK_SafeS16(int32_t V)
{
    AK_Assert(V >= AK_MinS16 && V <= AK_MaxS16);
    return (int16_t)V;
}

inline int16_t AK_SafeS16(int64_t V)
{
    AK_Assert(V >= AK_MinS16 && V <= AK_MaxS16);
    return (int16_t)V;
}

inline int32_t AK_SafeS32(uint32_t V)
{
    AK_Assert(V <= AK_MaxS32);
    return (int32_t)V;
}

inline int32_t AK_SafeS32(uint64_t V)
{
    AK_Assert(V <= AK_MaxS32);
    return (int32_t)V;
}

inline int32_t AK_SafeS32(int64_t V)
{
    AK_Assert(V >= AK_MinS32 && V <= AK_MaxS32);
    return (int32_t)V;
}

inline int64_t AK_SafeS64(uint64_t V)
{
    AK_Assert(V <= AK_MaxS64);
    return (uint64_t)V;
}

inline float  AK_Sqrt(float V)
{
    return sqrtf(V);
}

inline double AK_Sqrt(double V)
{
    return sqrt(V);
}

inline float  AK_Sin(float V)
{
    return sinf(V);
}

inline double AK_Sin(double V)
{
    return sin(V);
}

inline float  AK_Cos(float V)
{
    return cosf(V);
}

inline double AK_Cos(double V)
{
    return cos(V);
}

inline float AK_Tan(float V)
{
    return tanf(V);
}

inline double AK_Tan(double V)
{
    return tan(V);
}

inline float  AK_ASin(float V)
{
    return asinf(V);
}

inline double AK_ASin(double V)
{
    return asin(V);
}

inline float  AK_ACos(float V)
{
    return acosf(V);
}

inline double AK_ACos(double V)
{
    return acos(V);
}

inline float AK_ATan(float V)
{
    return atanf(V);
}

inline double AK_ATan(double V)
{
    return atan(V);
}

inline float AK_ATan2(float Y, float X)
{
    return atan2f(Y, X);
}

inline double AK_ATan2(double Y, double X)
{
    return atan2(Y, X);
}

inline float AK_Pow(float V, float Exp)
{
    return powf(V, Exp);
}

inline double AK_Pow(double V, double Exp)
{
    return pow(V, Exp);
}

inline float AK_Floor(float V)
{
    return floorf(V);
}

inline double AK_Floor(double V)
{
    return floor(V);
}

inline float AK_Ceil(float V)
{
    return ceilf(V);
}

inline double AK_Ceil(double V)
{
    return ceil(V);
}

inline float  AK_Round(float V)
{
    return roundf(V);
}

inline double AK_Round(double V)
{
    return round(V);
}

inline char AK_To_Upper(char C)
{
    if (('a' <= C) && (C <= 'z'))
        C -= 'a' - 'A';
    return C;
}

inline uint8_t AK_To_Upper(uint8_t C)
{
    if (('a' <= C) && (C <= 'z'))
        C -= 'a' - 'A';
    return C;
}

inline uint16_t AK_To_Upper(uint16_t C)
{
    if (('a' <= C) && (C <= 'z'))
        C -= 'a' - 'A';
    return C;
}

inline uint32_t AK_To_Upper(uint32_t C)
{
    if (('a' <= C) && (C <= 'z'))
        C -= 'a' - 'A';
    return C;
}

inline char AK_To_Lower(char C)
{
    if (('A' <= C) && (C <= 'Z'))
        C+= 'a' - 'A';
    return C;
}

inline uint8_t AK_To_Lower(uint8_t C)
{
    if (('A' <= C) && (C <= 'Z'))
        C+= 'a' - 'A';
    return C;
}

inline uint16_t AK_To_Lower(uint16_t C)
{
    if (('A' <= C) && (C <= 'Z'))
        C+= 'a' - 'A';
    return C;
}

inline uint32_t AK_To_Lower(uint32_t C)
{
    if (('A' <= C) && (C <= 'Z'))
        C+= 'a' - 'A';
    return C;
}

#ifdef AK_COMPILER_MSVC
inline int32_t AK_Atomic_Increment32(volatile int32_t* Addend)
{
    int32_t Result = _InterlockedIncrement((volatile long*)Addend);
    return Result;
}

inline int64_t AK_Atomic_Increment64(volatile int64_t* Addend)
{
    int64_t Result = _InterlockedIncrement64(Addend);
    return Result;
}

inline int32_t AK_Atomic_Decrement32(volatile int32_t* Addend)
{
    int32_t Result = _InterlockedDecrement((volatile long*)Addend);
    return Result;
}

inline int64_t AK_Atomic_Decrement64(volatile int64_t* Addend)
{
    int64_t Result = _InterlockedDecrement64(Addend);
    return Result;
}

inline int32_t AK_Atomic_Add32(volatile int32_t* Addend, int32_t Value)
{
    int32_t Result = _InterlockedExchangeAdd((volatile long*)Addend, Value);
    return Result;
}

inline int64_t AK_Atomic_Add64(volatile int64_t* Addend, int64_t Value)
{
    int64_t Result = _InterlockedExchangeAdd64(Addend, Value);
    return Result;
}

inline int32_t AK_Atomic_Exchange32(volatile int32_t* Dst, int32_t Value)
{
    int32_t Result = _InterlockedExchange((volatile long*)Dst, Value);
    return Result;
}

inline int64_t AK_Atomic_Exchange64(volatile int64_t* Dst, int64_t Value)
{
    int64_t Result = _InterlockedExchange64(Dst, Value);
    return Result;
}

inline void* AK_Atomic_ExchangePtr(volatile void** Dst, void* Value)
{
    void* Result = _InterlockedExchangePointer((volatile PVOID*)Dst, Value);
    return Result;
}

inline int32_t AK_Atomic_Compare_Exchange32(volatile int32_t* Dst, int32_t Exchange, int32_t Comperand)
{
    int32_t Result = _InterlockedCompareExchange((volatile long*)Dst, Exchange, Comperand);
    return Result;
}

inline int64_t AK_Atomic_Compare_Exchange64(volatile int64_t* Dst, int64_t Exchange, int64_t Comperand)
{
    int64_t Result = _InterlockedCompareExchange64(Dst, Exchange, Comperand);
    return Result;
}

inline void* AK_Atomic_Compare_ExchangePtr(volatile void** Dst, void* Exchange, void* Comperand)
{
    void* Result = _InterlockedCompareExchangePointer((volatile PVOID*)Dst, Exchange, Comperand);
    return Result;
}

#else
#error Not Implemented
#endif

#ifdef AK_OS_WIN32

#define AK__WIN32_SEMAPHORE_MAX_VALUE 512

struct ak__win32_thread_callback_data
{
    ak_thread_callback* Callback;
    void* UserData;
    HANDLE CreationEvent;
};

DWORD AK__Win32_Thread_Proc(LPVOID Parameter)
{
    ak__win32_thread_callback_data* Data = (ak__win32_thread_callback_data*)Parameter;
    ak_thread_callback* Callback = Data->Callback;
    void* UserData = Data->UserData;
    AK_Write_Barrier();
    SetEvent(Data->CreationEvent);
    return Callback(UserData);
}

ak_thread AK_Create_Thread(ak_thread_callback* ThreadCallback, void* UserData)
{
    ak__win32_thread_callback_data ThreadCallbackData = {};
    ThreadCallbackData.Callback = ThreadCallback;
    ThreadCallbackData.UserData = UserData;
    ThreadCallbackData.CreationEvent = CreateEventA(NULL, FALSE, FALSE, NULL);
    ak_thread Result = CreateThread(NULL, 0, AK__Win32_Thread_Proc, &ThreadCallbackData, 0, NULL);
    WaitForSingleObject(ThreadCallbackData.CreationEvent, INFINITE);
    CloseHandle(ThreadCallbackData.CreationEvent);
    return Result;
}

inline void AK_Wait_Thread(ak_thread Thread)
{
    WaitForSingleObject(Thread, INFINITE);
}

inline void AK_Delete_Thread(ak_thread Thread)
{
    CloseHandle(Thread);
}

inline ak_mutex AK_Create_Mutex()
{
    ak_mutex Result;
    InitializeCriticalSection(&Result);
    return Result;
}

inline void AK_Lock_Mutex(ak_mutex Mutex)
{
    EnterCriticalSection(&Mutex);
}

inline void AK_Unlock_Mutex(ak_mutex Mutex)
{
    LeaveCriticalSection(&Mutex);
}

inline void AK_Delete_Mutex(ak_mutex Mutex)
{
    DeleteCriticalSection(&Mutex);
}

inline ak_semaphore AK_Create_Semaphore(uint32_t InitialCount)
{
    ak_semaphore Semaphore = CreateSemaphoreA(NULL, InitialCount, AK__WIN32_SEMAPHORE_MAX_VALUE, NULL);
    return Semaphore;
}

inline void AK_Decrement_Semaphore(ak_semaphore Semaphore)
{
    WaitForSingleObject(Semaphore, INFINITE);
}

inline void AK_Increment_Semaphore(ak_semaphore Semaphore)
{
    ReleaseSemaphore(Semaphore, 1, NULL);
}

inline void AK_Delete_Semaphore(ak_semaphore Semaphore)
{
    CloseHandle(Semaphore);
}

ak_event AK_Create_Event()
{
    ak_event Event = CreateEventA(NULL, FALSE, FALSE, NULL);
    return Event;
}

void AK_Wait_Event(ak_event Event)
{
    WaitForSingleObject(Event, INFINITE);
}

void AK_Signal_Event(ak_event Event)
{
    SetEvent(Event);
}

void AK_Delete_Event(ak_event Event)
{
    CloseHandle(Event);
}

#else
#error Not Implemented
#endif

inline void ak_spin_lock::Lock()
{
    int64_t PreviousTarget = AK_Atomic_Add64(&Target, 1);
    while(PreviousTarget != Current) { _mm_pause(); }
}

inline void ak_spin_lock::Unlock()
{
    AK_Atomic_Increment64(&Current);
}

#endif