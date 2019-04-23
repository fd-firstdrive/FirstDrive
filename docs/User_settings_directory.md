FirstDrive stores user settings (mostly in [FirstDrive.config](FirstDrive_config.md)) and other information in a special directory on the computer's drive. Usually it is located within the user's personal assigned file space, to ensure that the user will have easy access to the files (for backup or other purposes), and that FirstDrive will be allowed write privileges to the directory.

Location
--------

The location of the settings directory is chosen based on the best location for the user's operating system. In the following subsections, *username* represents the user's login name on the computer.

|                      |                                                                       |
|----------------------|-----------------------------------------------------------------------|
| **Operating System** | **Location**                                                          |
| Windows XP           | `C:\Documents and Settings\''username''\My Documents\My Games\FirstDrive` |
| Windows Vista/7      | `C:\Users\''username''\AppData\Roaming\FirstDrive`                        |
| OS X                 | `/Users/''username''/Library/Preferences/FirstDrive`                      |
| Linux                | `/home/''username''/.vdrift`                                          |
| FreeBSD              | `/home/''username''/.vdrift`                                          |

<Category:Files>
