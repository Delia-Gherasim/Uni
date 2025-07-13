from ui import UI
#from adresses import *

import readtext 
all_adresses=readtext.read_text_file("addresses.txt")

UI=UI(all_adresses)
UI.menu()