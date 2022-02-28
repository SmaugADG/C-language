动态库和静态库的实现

* 静态库：

  编译的时候引入，占用编译时间

  > 格式：libxx.a，需要以lib开头
  >
  > 命令:ar -cr libxx.a yyy.o

  发布到

  > /usr/local/include      (.h文件)
  >
  > /usr/local/lib 	(.a文件)
  >
  > 
  >
  > gcc -L /usr/local/lib -o mian main.o -lxx
  >
  > -l参数必须在最后，有依赖

* 动态库：

  运行时引入

  > 格式：libxxx.so
  >
  > 命令：gcc -shared -fPIC -o libxx.so yyy.c

  发布到

  > /usr/local/include	(.h)
  >
  > /usr/local/lib	(.so)
  >
  > 
  >
  > 在 /etc/ld.so.conf 中添加路径：/usr/local/lib/
  >
  > /sbin/ldconfig  会重读 /etc/ld.so.conf
  >
  > gcc -I/usr/local/include -L/usr/local/lib  -o ...-lxx
  >
  > ldd命令可以看到可执行文件运行时需要的库文件
  >
  > 重名时，优先链接动态库

  > 非root用户发布
  >
  > cp xx.so ~/lib
  >
  > expot LD_LIBRARY_PATH=~/lib

