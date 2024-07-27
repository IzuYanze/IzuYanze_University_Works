import pygsheets
import json

#print(sh.sheet1.rows)

def update():

    client = pygsheets.authorize(service_account_file="secret")

    # Open the spreadsheet and the first sheet.
    sh = client.open_by_url("secret")

    with open("secret",'r') as file:
        List = json.load(file)


    for row_number in range(List["Start_row"],List["Start_row"]+50):
        check = (row_number,1)
        if str(sh.sheet1.get_value(check)) == '':
            break

        t1 = (row_number,2)
        t2 = (row_number,3)
        t3 = (row_number,4)
        t4 = (row_number,5)
        t5 = (row_number,6)
        New_restaurant = {
            "Name" : f"{sh.sheet1.get_value(t1)}",
            "Location" : f"{sh.sheet1.get_value(t2)}",
            "Time" : f"{sh.sheet1.get_value(t3)}",
            "Type" : f"{sh.sheet1.get_value(t4)}",
            "Staple" : f"{sh.sheet1.get_value(t5)}"
        }
        #print(New_restaurant)
        if New_restaurant["Name"] not in List["NameList"] :
            with open("secret",'r+') as file:
                data = json.load(file)
                data["restaurant"].append(New_restaurant)
                data["NameList"].append(New_restaurant["Name"])
                file.seek(0)
                json.dump(data,file,ensure_ascii=True,indent=4)
        
        Next = (row_number+1,1)
        if str(sh.sheet1.get_value(Next)) == '':
            with open("secret",'r+') as file:
                data = json.load(file)
                data["Start_row"] = row_number+1
                file.seek(0)
                json.dump(data,file,ensure_ascii=True,indent=4)
            break


if __name__ == "__main__":
    update()
