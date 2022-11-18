import sqlite3
from pprint import pprint

conn = sqlite3.connect('C:/Users/SamiDhiab/Theion_Repos/soft_wgm_user_interface_qt_cpp/build/dependencies/database/Debug/testDb.db')
cursor = conn.execute("PRAGMA table_info(PERSON);")
results = cursor.fetchall()
pprint(results)