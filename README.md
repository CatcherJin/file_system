# file_system
C++实现的一个仿Linux的简易文件系统

# # 1.系统设计方法：用C++实现，每部分功能用函数封装。
①	初始化系统（format）:初始化用户8个，用户名密码写进程序里面。并且在D盘下创建filesystem文件，用于存储系统信息。
②	读取目前已有的系统信息（install）：读取D盘下filesystem文件信息。
③	显示当前目录中的子目录和文件（dir）：dir()函数，输出目录与文件信息。
④	创建目录（mkdir）：mkdir(char filename[8])函数，传入参数目录名，在当前目录下创建新的目录。
⑤	改变当前目录（chdir）：chdir(char filename[8])函数，传入参数目录名，跳转到输入的目录下。
⑥	创建文件（create）: create_(char filename[8])函数，输入文件名，在当前目录下创建文件。
⑦	删除文件（delete）：delete_(char filename[8])函数，传入文件名，删除文件。
⑧	打开文件（open）：open(char filename[8])函数，传入文件名，打开文件。
⑨	关闭文件（close）：close_()函数，关闭当前打开的文件。
⑩	读文件（read）: read(char filename[8])函数，传入文件名，读取当前打开的文件内容。
⑪	写文件（write）: write(char filename_[8],char filename[16])函数，传入文件名和要写入的内容，写入内容到文件中。
⑫	保存结果并退出系统（logout）：filesys_exit()函数，保存当前信息到D盘下的filesystem文件中去并退出。

2.实现的功能及说明
①	多用户操作：系统初始化有8个用户jin1/jin2/jin3/jin4/jin5/jin6/jin7/jin8，密码都为123。
②	能实现文件保护操作：用户不能对其他用户创建的文件进行操作，例如jin1用户创建的test文件，其他用户不能打开，以实现文件的保护。
③	系统有层次结构：系统在一个目录下还可以再创建目录，可以进入子目录也可以返回到上一目录，一层层，实现文件系统的层次结构。
④	能实现create、open、close、read/write等文件操作功能，写入文件能将一串字符串写入到当前打开的文件中。下次创建该文件的用户可以read，也可以继续write修改。
⑤	能输出当前所在的目录，也可以输出当前目录下所有的子目录和文件（dir）。
⑥	能实现系统的存储功能，下次打开系统时想要读取之前所记录的信息，可以读取D盘下filesystem文件来恢复，也可以选择格式化系统，重新建立目录和文件，退出系统时会保存当前信息到D盘下的filesystem文件中。
