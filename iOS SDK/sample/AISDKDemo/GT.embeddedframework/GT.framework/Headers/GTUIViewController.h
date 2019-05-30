//
//  UIViewController+GT.h
//  GTKit
//
//  Created   on 13-4-1.
//  Copyright ©[Insert Year of First Publication] - 2014 Tencent.All Rights Reserved. This software is licensed under the terms in the LICENSE.TXT file that accompanies this software.
//
#ifndef GT_DEBUG_DISABLE
#import <UIKit/UIKit.h>

@interface GTUIViewController : UIViewController
{
    BOOL              _topBarCreated;
    UINavigationBar  *_navBar;
    UINavigationItem *_navItem;
}

@property (nonatomic, retain) UINavigationBar  *navBar;
@property (nonatomic, retain) UINavigationItem *navItem;

- (void)createTopBar;
- (void)setNavBarHidden:(BOOL)hidden;
- (void)setNavTitle:(NSString *)title;
- (NSArray *)leftBarButtonItems;
- (NSArray *)rightBarButtonItems;

@end
#endif