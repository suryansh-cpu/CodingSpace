class Solution{
public: 
    void cleanRoom(Robot& robot){
        robot.clean();
        if(robot.move() == true){
            cleanRoom(robot.move());
        }
        // else return ;
        if(robot.move() == true){
            cleanRoom(robot.move());
        }
        robot.turnLeft();
        if(robot.move() == true){cleanRoom(robot.move());}
        // cleanRoom(robot.move());
        // robot.turnLeft();
        if(robot.move() == true){cleanRoom(robot.move());}
    }
};