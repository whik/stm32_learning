@echo off

::批量将指定目录中的所有C文件用Astyle进行代码美化操作，支持鼠标拖动操作
::参考http://blog.chinaunix.net/uid-23381466-id-58917.html
::参考http://blog.csdn.net/windcao/article/details/12319225

::设置astyle.exe执行路径
set astyle=%~dp0\astyle.exe

::循环遍历目录查找指定文件进行处理
for /r %~dp1%~nx1 %%a in (.) do %astyle% %%a\*.cpp --style=linux -s4 -S -N -L -m0 -M40 --recursive --convert-tabs %f
for /r %~dp1%~nx1 %%a in (.) do %astyle% %%a\*.c   --style=linux -s4 -S -N -L -m0 -M40 --recursive --convert-tabs %f
for /r %~dp1%~nx1 %%a in (.) do %astyle% %%a\*.hpp --style=linux -s4 -S -N -L -m0 -M40 --recursive --convert-tabs %f
for /r %~dp1%~nx1 %%a in (.) do %astyle% %%a\*.h   --style=linux -s4 -S -N -L -m0 -M40 --recursive --convert-tabs %f
for /r %~dp1%~nx1 %%a in (.) do %astyle% %%a\*.s   --style=linux -s4 -S -N -L -m0 -M40 --recursive --convert-tabs %f

::删除astyle生成的所有中间文件
for /r %~dp1%~nx1 %%a in (*.orig) do del %%a

pause