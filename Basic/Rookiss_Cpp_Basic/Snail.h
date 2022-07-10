#pragma once // �ߺ� ����

enum CrawlDirection
{
    Right,
    Down,
    Left,
    Up,
};

void Snail();
void Dot();
void Crawl();
bool Moveable();
void SetupSnail();
void PrintSnail();
void Turn();