# Auto-CLICKER
So I saw that there aren't any good auto-clickers out there, so I made this one in Python. You just click the ` button (under ESC) to start clicking, and pressing it again stops it.

### How to Compile It Yourself

1. Download the `Auto Clicker.py` file.
2. Download and install Python, making sure to:
   - Check the box that says "Add Python to PATH"
   - Select "Pip" during installation.
3. Open a terminal (or Command Prompt) and install the necessary libraries by running:
   ```bash
   pip install pyinstaller
   pip install keyboard
   pip install pynput

Once the dependencies are installed, run the following command to create the .exe file
```bash
pyinstaller --onefile --noconsole "C:\path\to\your\Auto Clicker.py"
```
   Great now your Executable is ready

If you don't want to compile it yourself, you can download the precompiled `.exe` file from the [Release page](link_to_release_page) and run it directly!
