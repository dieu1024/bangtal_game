//
//  main.cpp
//  bangtal_game (개인과제)
//
//  Created by 김지우
//

#include <bangtal>
using namespace bangtal;

class Rect {
public:
    int centerX, centerY;
    int radius;


    Rect(int cx, int cy, int r) : centerX(cx), centerY(cy), radius(r) {};
    bool checkIn(int x, int y) const {
        return (x > centerX - radius && x < centerX + radius && y > centerY - radius && y < centerY + radius);
    }
};

const auto check_radius = 32;

auto main_scene = Scene::create("", "img/main.png");
auto scenez = Scene::create("","img/zootopia.png");
auto scenec = Scene::create("","img/coco.png");
auto scenei = Scene::create("","img/insideout.png");

auto zoobutton = Object::create("img/zootopia_icon.png", main_scene,980,100);
auto cocobutton = Object::create("img/coco_icon.png", main_scene,800,400);
auto insidebutton = Object::create("img/insideout_icon.png", main_scene,70,350);

auto slash = Object::create("img/slash.png", main_scene,620,660,false);
auto difs = Object::create("img/five.png", main_scene,650,660,false);
auto check = Object::create("img/zero.png", main_scene,590,660,false);

auto heart = Object::create("img/heart3.png", main_scene,290, 660, false);

int count = 0;
int heart_count = 0;

void zoo_init (){
    scenez->enter();
    auto problem = Object::create("img/zootopia.png", scenez);

    Rect left_rects[5] = {
        {172, 177, 30},
        {110, 259, 30},
        {376, 533, 30},
        {545, 569, 30},
        {170, 93, 30}
    };

    Rect right_rects[5] = {
        {772, 177, 30},
        {710, 259, 30},
        {976, 533, 30},
        {1145, 569, 30},
        {770, 93, 30}
    };

    ObjectPtr left_checks[5];
    ObjectPtr right_checks[5];

    for (int i = 0; i < 5; ++i){
        left_checks[i]=Object::create("img/circle.png", scenez, left_rects[i].centerX-check_radius, left_rects[i].centerY-check_radius, false);
        right_checks[i]=Object::create("img/circle.png", scenez, right_rects[i].centerX-check_radius, right_rects[i].centerY-check_radius, false);
    }


    problem->setOnMouseCallback([=](auto, int x, int y, auto)->bool{
        
        bool checked = false;
        for (int i = 0; i<5; ++i){
            
            if(left_rects[i].checkIn(x, y)||right_rects[i].checkIn(x, y)){
                left_checks[i]->show();
                right_checks[i]->show();
                
                checked = true;
                
                count++;
                if(count==1) check->setImage("img/one.png");
                else if(count==2) check->setImage("img/two.png");
                else if(count==3) check->setImage("img/three.png");
                else if(count==4) check->setImage("img/four.png");
                else check->setImage("img/five.png");
            }
    }
        
    if (checked == false) {
        heart_count++;
        
        if(heart_count==1) heart->setImage("img/heart2.png");
        else if (heart_count==2) heart->setImage("img/heart1.png");
        else {
            main_scene->enter();
            zoobutton->show();
            cocobutton->show();
            insidebutton->show();
            count = 0;
            heart_count = 0;
            showMessage("하트가 없어요 ㅜ.ㅜ");
        }
    }


    if (count == 5){
        showMessage("Clear");
        count = 0;
    }

        return true;
    });
    
    auto exit = Object::create("img/exit.png", scenez,10,10);
    auto back = Object::create("img/arrow.png", scenez,10,650);
    auto hint = Object::create("img/hint.png", scenez,1200,650);
    
    exit->setOnMouseCallback([&](auto, auto, auto, auto)->bool {
            endGame();
            return true;
        });
    
    back->setOnMouseCallback([&](auto, auto, auto, auto)->bool {
            main_scene->enter();
            zoobutton->show();
            cocobutton->show();
            insidebutton->show();
            count = 0;
            heart_count = 0;
            return true;
        });
    
    hint->setOnMouseCallback([&](auto, auto, auto, auto)->bool {
            showMessage("1.햄스터 삼형제\n 2.아기코끼리\n 3.목걸이\n 4.눈썹\n 5.새로 지은 건물");
            return true;
        });
}

void coco_init (){
    scenec->enter();
    auto problem = Object::create("img/coco.png", scenec);

    Rect left_rects[4] = {
        {302, 213, 30},
        {417, 234, 30},
        {480, 450, 30},
        {199, 349, 30}
    };

    Rect right_rects[4] = {
        {902, 213, 30},
        {1017, 234, 30},
        {1080, 450, 30},
        {799, 349, 30}
    };

    ObjectPtr left_checks[4];
    ObjectPtr right_checks[4];

    for (int i = 0; i < 4; ++i){
        left_checks[i]=Object::create("img/circle.png", scenec, left_rects[i].centerX-check_radius, left_rects[i].centerY-check_radius, false);
        right_checks[i]=Object::create("img/circle.png", scenec, right_rects[i].centerX-check_radius, right_rects[i].centerY-check_radius, false);
    }


    problem->setOnMouseCallback([=](auto, int x, int y, auto)->bool{
        bool checked = false;
        for (int i = 0; i<4; ++i){
            if(left_rects[i].checkIn(x, y)||right_rects[i].checkIn(x, y)){
                left_checks[i]->show();
                right_checks[i]->show();
                checked = true;
                
                count++;
                if(count==1) check->setImage("img/one.png");
                else if(count==2) check->setImage("img/two.png");
                else if(count==3) check->setImage("img/three.png");
                else check->setImage("img/four.png");
            }
    }

        if (checked == false) {
            heart_count++;
            
            if(heart_count==1) heart->setImage("img/heart2.png");
            else if (heart_count==2) heart->setImage("img/heart1.png");
            else {
                main_scene->enter();
                zoobutton->show();
                cocobutton->show();
                insidebutton->show();
                count = 0;
                heart_count = 0;
                showMessage("하트가 없어요 ㅜ.ㅜ");
            }
        }

    if (count == 4){
        showMessage("Clear");
        count = 0;
    }

        return true;
    });
    
    auto exit = Object::create("img/exit.png", scenec,10,10);
    auto back = Object::create("img/arrow.png", scenec,10,650);
    auto hint = Object::create("img/hint.png", scenec,1200,650);
    
    exit->setOnMouseCallback([&](auto, auto, auto, auto)->bool {
            endGame();
            return true;
        });
    
    back->setOnMouseCallback([&](auto, auto, auto, auto)->bool {
            main_scene->enter();
            zoobutton->show();
            cocobutton->show();
            insidebutton->show();
            count = 0;
            heart_count = 0;
            return true;
        });
    
    hint->setOnMouseCallback([&](auto, auto, auto, auto)->bool {
            showMessage("1.할아버지 모자\n 2.턱\n 3.금 목걸이\n 4.미구엘은 나이키를 입는다");
            return true;
        });


}

void inside_init (){
    scenei->enter();
    auto problem = Object::create("img/insideout.png", scenei);

    Rect left_rects[5] = {
        {34, 360, 30},
        {205, 482, 30},
        {331, 127, 30},
        {272, 244, 30},
        {587, 528, 30}
    };

    Rect right_rects[5] = {
        {660, 360, 30},
        {855, 482, 30},
        {961, 127, 30},
        {902, 244, 30},
        {1237, 528, 30}
    };

    ObjectPtr left_checks[5];
    ObjectPtr right_checks[5];

    for (int i = 0; i < 5; ++i){
        left_checks[i]=Object::create("img/circle.png", scenei, left_rects[i].centerX-check_radius, left_rects[i].centerY-check_radius, false);
        right_checks[i]=Object::create("img/circle.png", scenei, right_rects[i].centerX-check_radius, right_rects[i].centerY-check_radius, false);
    }


    problem->setOnMouseCallback([=](auto, int x, int y, auto)->bool{
        bool checked = false;
        for (int i = 0; i<5; ++i){
            if(left_rects[i].checkIn(x, y)||right_rects[i].checkIn(x, y)){
                left_checks[i]->show();
                right_checks[i]->show();
                checked = true;
                
                count++;
                if(count==1) check->setImage("img/one.png");
                else if(count==2) check->setImage("img/two.png");
                else if(count==3) check->setImage("img/three.png");
                else if(count==4) check->setImage("img/four.png");
                else check->setImage("img/five.png");
            }
    }

        if (checked == false) {
            heart_count++;
            
            if(heart_count==1) heart->setImage("img/heart2.png");
            else if (heart_count==2) heart->setImage("img/heart1.png");
            else {
                main_scene->enter();
                zoobutton->show();
                cocobutton->show();
                insidebutton->show();
                count = 0;
                heart_count = 0;
                showMessage("하트가 없어요 ㅜ.ㅜ");
            }
        }

    if (count == 5){
        showMessage("Clear");
        count = 0;
    }

        return true;
    });
    
    auto exit = Object::create("img/exit.png", scenei,10,10);
    auto back = Object::create("img/arrow.png", scenei,10,650);
    auto hint = Object::create("img/hint.png", scenei,1200,650);
    
    exit->setOnMouseCallback([&](auto, auto, auto, auto)->bool {
            endGame();
            return true;
        });
    back->setOnMouseCallback([&](auto, auto, auto, auto)->bool {
            main_scene->enter();
            zoobutton->show();
            cocobutton->show();
            insidebutton->show();
            count = 0;
            heart_count = 0;
            return true;
        });
    hint->setOnMouseCallback([&](auto, auto, auto, auto)->bool {
            showMessage("1.슬퍼진 구슬\n 2.이빨빠진 호랑이\n 3.감정 조절 기계\n 4.새로 생긴 건물\n 5.미용실 다녀온 기쁨이");
            return true;
        });

}

int main()
{
    setGameOption(GameOption::GAME_OPTION_ROOM_TITLE, false);
    setGameOption(GameOption::GAME_OPTION_MESSAGE_BOX_BUTTON, false);
    setGameOption(GameOption::GAME_OPTION_INVENTORY_BUTTON, false);


    zoobutton->setOnMouseCallback([&](auto, auto, auto, auto)->bool{
        zoo_init();
        zoobutton->hide();
        cocobutton->hide();
        insidebutton->hide();
        
        check->setImage("img/zero.png");
        difs->setImage("img/five.png");
        slash->show();
        difs->show();
        check->show();
        heart->show();
        
        slash->locate(scenez,620,660);
        difs->locate(scenez,650,660);
        check->locate(scenez,590,660);
        heart->locate(scenez,290,660);
        
        slash->setScale(0.7f);
        difs->setScale(0.7f);
        check ->setScale(0.7f);
        heart->setImage("img/heart3.png");
        
        return true;
    });

    cocobutton->setOnMouseCallback([&](auto, auto, auto, auto)->bool{
        coco_init();
        zoobutton->hide();
        cocobutton->hide();
        insidebutton->hide();
        
        check->setImage("img/zero.png");
        difs->setImage("img/four.png");
        slash->show();
        difs->show();
        check->show();
        heart->show();
        
        slash->locate(scenec,620,660);
        difs->locate(scenec,650,660);
        check->locate(scenec,590,660);
        heart->locate(scenec,290,660);
        
        slash->setScale(0.7f);
        difs->setScale(0.7f);
        check ->setScale(0.7f);
        heart->setImage("img/heart3.png");
        
        return true;
    });

    insidebutton->setOnMouseCallback([&](auto, auto, auto, auto)->bool{
        inside_init();
        zoobutton->hide();
        cocobutton->hide();
        insidebutton->hide();
        
        check->setImage("img/zero.png");
        difs->setImage("img/five.png");
        slash->show();
        difs->show();
        check->show();
        heart->show();
        
        slash->locate(scenei,620,660);
        difs->locate(scenei,650,660);
        check->locate(scenei,590,660);
        heart->locate(scenei,290,660);
        
        slash->setScale(0.7f);
        difs->setScale(0.7f);
        check ->setScale(0.7f);
        heart->setImage("img/heart3.png");
        
        return true;
    });

    auto exit = Object::create("img/exit.png", main_scene,10,10);
    exit->setOnMouseCallback([&](auto, auto, auto, auto)->bool {
            endGame();
            return true;
        });
    
    startGame(main_scene);
  
}

