# Green Piece Game by VegaSoft :brazil:

## Windows users GIT configuration
```console
git config --global core.autocrlf input
```
```console
git config --global --add safe.directory ur_project's_path
```
```console
git config --global lfs.contenttype 0
```

## Network
- Online Beacons are a special type of Actor that provide a lightweight way to contact a server and interact with it (via RPCs) without committing to a normal game connection. While the built-in classes can be used as they are in some cases, they are intended to be extended into custom classes that perform project-specific interactions, logic, and information requests.    
[OnlineBeacon](https://docs.unrealengine.com/4.27/en-US/InteractiveExperiences/Networking/OnlineBeacons/)   
[OnlineSubsystemUtils](https://docs.unrealengine.com/4.26/en-US/API/Plugins/OnlineSubsystemUtils/)    

### Enabling Windows Long Path
- Execute Windows+r then type gpedit.msc and run.
- Click Window key and type gpedit.msc, then press the Enter key. This launches the Local Group Policy Editor.
- Navigate to Local Computer Policy > Computer Configuration > Administrative Templates > System > Filesystem.
- Double click Enable NTFS long paths.
- Select Enabled, then click OK.
- At last restart visual studio

Made with :heart:. Todos os direitos reservados. Green Piece ID:929641795 Copyright © Vega Soft :star:.