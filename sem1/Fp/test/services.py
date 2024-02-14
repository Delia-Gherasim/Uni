from entities import Adress

class service:
    def __init__(self, adresses):
        self.adresses=adresses

    def add_to_file(self, id, name, number, x, y):
        adr={"id":id, "name":name, "number":number, "x":x, "y":y}
        Adres=self.adresses
        Adres.append(adr)
        #info=str({"id":id, "name":name, "number":number, "x":x, "y":y})
        #with open("addresses.txt", "a") as f:
         #   f.writelines("\n")
          #  f.writelines(info)

        #info=str(adr)
        #with open("addresses.txt", "w") as f:
         #   f.writelines(info)

    def nr3(self, x, y, d):
        """function computes the 3rd requirment
        
        :param x: new coord x, int
        :param y: new coord y. int
        :param d:distance to compare to, int"""
        new=[]
        for i in range(len(self.adresses)-1):
            Adr=self.adresses[i]
            #x2=get_x(self.adresses[i])
            y2=Adress.get_y(self.adresses[i])
            d2=sqrt((x-x2)*(x-x2)+(y-y2)*(y-y2))
            if d2<=d:
                new.append(self.adresses[i])
        return new

    def nr4(self):
        new=[]
        sumx=0
        sumy=0
        for i in range(len(self.adresses)-1):
            Adr=self.adresses[i]
            x=get_x(self.adresses[i])
            y=entities.Adress.get_y(Adr)
            sumx=x+sumx
            sumy=y+sumy
        d=len(self.adresses)
        sumx=sumx//d
        sumy=sumy//d
        if sumx>-100 and sumx<100:
            if sumy>-100 and sumy<100:
                return sumx, sumy

