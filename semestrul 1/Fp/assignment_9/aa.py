
import PySimpleGUI as sg

layout = [[sg.Button(str(i), size=(3, 1)) for i in range(10)] for j in range(10)]

window = sg.Window('Grid', layout)

while True:
    event, values = window.read()
    if event in (None, 'Exit'):
        break
    print(event, values)

window.close()