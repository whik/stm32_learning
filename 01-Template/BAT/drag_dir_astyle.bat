@echo off

::������ָ��Ŀ¼�е�����C�ļ���Astyle���д�������������֧������϶�����
::�ο�http://blog.chinaunix.net/uid-23381466-id-58917.html
::�ο�http://blog.csdn.net/windcao/article/details/12319225

::����astyle.exeִ��·��
set astyle=%~dp0\astyle.exe

::ѭ������Ŀ¼����ָ���ļ����д���
for /r %~dp1%~nx1 %%a in (.) do %astyle% %%a\*.cpp --style=linux -s4 -S -N -L -m0 -M40 --recursive --convert-tabs %f
for /r %~dp1%~nx1 %%a in (.) do %astyle% %%a\*.c   --style=linux -s4 -S -N -L -m0 -M40 --recursive --convert-tabs %f
for /r %~dp1%~nx1 %%a in (.) do %astyle% %%a\*.hpp --style=linux -s4 -S -N -L -m0 -M40 --recursive --convert-tabs %f
for /r %~dp1%~nx1 %%a in (.) do %astyle% %%a\*.h   --style=linux -s4 -S -N -L -m0 -M40 --recursive --convert-tabs %f
for /r %~dp1%~nx1 %%a in (.) do %astyle% %%a\*.s   --style=linux -s4 -S -N -L -m0 -M40 --recursive --convert-tabs %f

::ɾ��astyle���ɵ������м��ļ�
for /r %~dp1%~nx1 %%a in (*.orig) do del %%a

pause