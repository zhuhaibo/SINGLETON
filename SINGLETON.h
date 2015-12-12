#import <Foundation/Foundation.h>
/*头文件中生命函数*/
#define SINGLETONH(name) + (instancetype)shared##name;
/*执行文件中实现函数*/
#define SINGLETONM(name)\
static id _instance;\
+ (instancetype)allocWithZone:(struct _NSZone *)zone\
{\
static dispatch_once_t onceToken;\
dispatch_once(&onceToken, ^{\
_instance = [super allocWithZone:zone];\
});\
\
return _instance;\
}\
\
/** 提供创建单例的类方法 */\
+ (instancetype)shared##name\
{\
static dispatch_once_t onceToken;\
dispatch_once(&onceToken, ^{\
_instance = [[self alloc] init];\
});\
return _instance;\
}\
\
/** copy也返回一个对象 */\
- (id)copyWithZone:(NSZone *)zone\
{\
return _instance;\
}