@ echo off
%1 %2
ver|find "5.">nul&&goto :Admin
mshta vbscript:createobject("shell.application").shellexecute("%~s0","goto :Admin","","runas",1)(window.close)&goto :eof
:Admin

copy "\\vmware-host\Shared Folders\sharefolder\r3\CrowAntiCheat_Client.exe" "C:\Users\sword\Desktop\"
copy "\\vmware-host\Shared Folders\sharefolder\r3\CrowAntiCheat_Client.pdb" "C:\Users\sword\Desktop\"
copy "\\vmware-host\Shared Folders\sharefolder\r3\CrowAntiCheat_Client.ipdb" "C:\Users\sword\Desktop\"
copy "\\vmware-host\Shared Folders\sharefolder\r3\CrowAntiCheat_Client.iobj" "C:\Users\sword\Desktop\"
copy "\\vmware-host\Shared Folders\sharefolder\r0\test.sys" "C:\Users\sword\Desktop\"


cd C:\Users\sword\Desktop\
echo WScript.sleep 1000 > sleep.vbs
Wscript sleep.vbs
start Dbgview.exe
Wscript sleep.vbs
start CrowAntiCheat_Client.exe
Wscript sleep.vbs
#start csgo.exe


#https://jingyan.baidu.com/article/0eb457e5da338103f1a905f6.html
#根据这个网页内容，适当配置虚拟机，拍摄快照