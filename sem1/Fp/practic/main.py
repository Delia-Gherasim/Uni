from ui import ui
from practic.repository import repo

Repo=repo.matrix()
UI=ui(Repo)
UI.start()