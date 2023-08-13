class ParkingSystem:

    def __init__(self, big: int, medium: int, small: int):
        self.lot = {}
        self.lot[1] = big
        self.lot[2] = medium
        self.lot[3] = small

    def addCar(self, carType: int) -> bool:
        if not self.lot.get(carType):
            return False
        elif self.lot.get(carType) > 0:
            self.lot[carType] -= 1
            return True

# Your ParkingSystem object will be instantiated and called as such:
# obj = ParkingSystem(big, medium, small)
# param_1 = obj.addCar(carType)
