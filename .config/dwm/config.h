/* See LICENSE file for copyright and license details. */

/* appearance */
static const unsigned int borderpx  = 3;        /* border pixel size of windows */
static const unsigned int gappx     = 5;        /* gaps size between windows */
static const unsigned int gappih    = 30;
static const unsigned int gappiv    = 30;
static const unsigned int gappoh    = 30;
static const unsigned int gappov    = 30;
static const unsigned int snap      = 32;       /* snap pixel */
static                int smartgaps = 0;
static const int showbar            = 1;        /* 0 means no bar */
static const int topbar             = 1;        /* 0 means bottom bar */
static const char *fonts[]          = { "JetBrains Mono NL:pixelsize=14:antialias=true:autohint=true" };
//static const char dmenufont[]       = "JetBrains Mono NL:pixelsize=14:antialias=true:autohint=true";
//background color
static const char col_gray1[]       = "#222222";
static const char col_gray2[]       = "#444444";
static const char col_gray3[]       = "#d8e2ed";
static const char col_gray4[]       = "#d8e2ed";
static const char col_gray5[]       = "#757a80";
static const char col_cyan[]        = "#7575a3";
static const char *colors[][3]      = {
	/*               fg         bg         border   */
	[SchemeNorm] = { col_gray3, col_gray1, col_gray2 },
	[SchemeSel]  = { col_gray4, col_cyan,  col_gray5  },
};

/* tagging */
//tag names (upper left)
static const char *tags[] = { "", "", "", "", "", };

static const Rule rules[] = {
	/* xprop(1):
	 *	WM_CLASS(STRING) = instance, class
	 *	WM_NAME(STRING) = title
	 */
	/* class      instance    title       tags mask     isfloating   monitor */
	{ "Gimp",     NULL,       NULL,       0,            1,           -1 },
	{ "LibreWolf",  NULL,       NULL,       1 << 8,       0,           -1 },
};

/* layout(s) */
static const float mfact     = 0.55; /* factor of master area size [0.05..0.95] */
static const int nmaster     = 1;    /* number of clients in master area */
static const int resizehints = 1;    /* 1 means respect size hints in tiled resizals */

static const Layout layouts[] = {
	/* symbol     arrange function */
	{ "[]=",      tile },    /* first entry is default */
	{ "><>",      NULL },    /* no layout function means floating behavior */
	{ "[M]",      monocle },
};

/* key definitions */
#define MODKEY Mod4Mask
#define TAGKEYS(KEY,TAG) \
	{ MODKEY,                       KEY,      view,           {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask,           KEY,      toggleview,     {.ui = 1 << TAG} }, \
	{ MODKEY|ShiftMask,             KEY,      tag,            {.ui = 1 << TAG} }, \
	{ MODKEY|ControlMask|ShiftMask, KEY,      toggletag,      {.ui = 1 << TAG} },

/* helper for spawning shell commands in the pre dwm-5.0 fashion */
#define SHCMD(cmd) { .v = (const char*[]){ "/bin/sh", "-c", cmd, NULL } }

/* commands */
static char dmenumon[2] = "0"; /* component of dmenucmd, manipulated in spawn() */
//static const char *dmenucmd[] = { "dmenu_run", "-m", dmenumon, "-fn", dmenufont, "-nb", col_gray1, "-nf", col_gray3, "-sb", col_cyan, "-sf", col_gray4, NULL };
static const char *dmenucmd[] = { "rofi", "-theme", "dracula", "-show", "drun", "-icon-theme", "Papirus", "-show-icons", NULL };
static const char *monitor[] = { "/usr/bin/htop", NULL };
static const char *termcmd[]  = { "alacritty", NULL };
static const char *upvol[]   = { "amixer", "-q", "set", "Master", "5%+", "unmute", NULL };
static const char *downvol[] = { "amixer", "-q", "set", "Master", "5%-", "unmute", NULL };
static const char *mutevol[] = { "amixer", "-q", "set", "Master", "toggle", NULL };
static const char *pctlplaycmd[]  = { "playerctl", "play-pause", NULL };
static const char *pctlpausecmd[]  = { "playerctl", "pause", NULL };
static const char *pctlnextcmd[]  = { "playerctl", "next", NULL };
static const char *pctlpreviouscmd[]  = { "playerctl", "previous", NULL };
static const char *brightnessupcmd[]  = { "/usr/local/bin/brightlight", "-p", "-i", "10", NULL };
static const char *brightnessdowncmd[]  = { "/usr/local/bin/brightlight", "-p", "-d", "10", NULL };
static const char *scrotcmd[]  = { "scrot", "-t", "25", NULL };
static const char *scrotfocusedcmd[]  = { "scrot", "--focused", NULL };

#include "shiftview.c"
#include <X11/XF86keysym.h>
static char *endx[] = { "/bin/sh", "-c", "endx", "externalpipe", NULL };
static Key keys[] = {
	/* modifier                     key        function        argument */
	{ MODKEY,                       XK_space,      spawn,          {.v = dmenucmd } },
	{ MODKEY,	                    XK_Return, spawn,          {.v = termcmd } },
	{ MODKEY,                           XK_Escape, spawn,          {.v = monitor } },
	{ MODKEY,                       XK_t,      togglebar,      {0} },
	{ MODKEY,                       XK_j,      focusstack,     {.i = +1 } },
	{ MODKEY,                       XK_k,      focusstack,     {.i = -1 } },
	{ MODKEY,                       XK_i,      incnmaster,     {.i = +1 } },
	{ MODKEY,                       XK_u,      incnmaster,     {.i = -1 } },
	{ MODKEY,                       XK_h,      setmfact,       {.f = -0.05} },
	{ MODKEY,                       XK_l,      setmfact,       {.f = +0.05} },
	{ MODKEY,                       XK_z,	   zoom,           {0} },
	{ MODKEY,                       XK_Tab,    view,           {0} },
	{ MODKEY,	                    XK_q,      killclient,     {0} },
	{ MODKEY|ShiftMask,             XK_t,      setlayout,      {.v = &layouts[0]} },
	{ MODKEY|ShiftMask,             XK_f,      setlayout,      {.v = &layouts[1]} },
	{ MODKEY|ShiftMask,             XK_m,      setlayout,      {.v = &layouts[2]} },
	{ MODKEY|ShiftMask,             XK_space,  setlayout,      {0} },
	{ MODKEY|ShiftMask,             XK_space,  togglefloating, {0} },
	{ MODKEY,                       XK_0,      view,           {.ui = ~0 } },
	{ MODKEY|ShiftMask,             XK_0,      tag,            {.ui = ~0 } },
	{ MODKEY,                       XK_comma,  focusmon,       {.i = -1 } },
	{ MODKEY,                       XK_period, focusmon,       {.i = +1 } },
	{ MODKEY,                       XK_minus,  setgaps,        {.i = -1 } },
	{ MODKEY,                       XK_equal,  setgaps,        {.i = +1 } },
	{ MODKEY|ShiftMask,             XK_equal,  setgaps,        {.i = 0  } },
	{ MODKEY|ShiftMask,             XK_comma,  tagmon,         {.i = -1 } },
	{ MODKEY|ShiftMask,             XK_period, tagmon,         {.i = +1 } },
  { 0,                            XF86XK_AudioPlay,          spawn,      {.v = pctlplaycmd } },
	{ 0,                            XF86XK_AudioPause,         spawn,      {.v = pctlpausecmd } },
	{ 0,                            XF86XK_AudioNext,          spawn,      {.v = pctlnextcmd } },
	{ 0,                            XF86XK_AudioPrev,          spawn,      {.v = pctlpreviouscmd } },
	{ 0,                            XF86XK_MonBrightnessUp,    spawn,      {.v = brightnessupcmd } },
	{ 0,                            XF86XK_MonBrightnessDown,  spawn,      {.v = brightnessdowncmd } },
  { 0,            XK_Print,   spawn,      {.v = scrotcmd } },
  { MODKEY|ShiftMask,                    XK_Print,   spawn,      {.v = scrotfocusedcmd } },
  { MODKEY,                       XK_s,   spawn,      SHCMD("sleep 1s;scrot --select") },
  { MODKEY,              		      XK_n,      shiftview,  	   { .i = +1 } },
	{ MODKEY,              		      XK_b,      shiftview,      { .i = -1 } },
  { MODKEY,                       XK_p,     spawn,          {.v = upvol   } },
  { MODKEY,                       XK_o,     spawn,          {.v = downvol } },
  { MODKEY,                       XK_y,     spawn,          {.v = mutevol } },
  TAGKEYS(                        XK_1,                      0)
	TAGKEYS(                        XK_2,                      1)
	TAGKEYS(                        XK_3,                      2)
	TAGKEYS(                        XK_4,                      3)
	TAGKEYS(                        XK_5,                      4)
	TAGKEYS(                        XK_6,                      5)
	TAGKEYS(                        XK_7,                      6)
	TAGKEYS(                        XK_8,                      7)
	TAGKEYS(                        XK_9,                      8)
	{ MODKEY|ShiftMask,             XK_q,      quit,           {0} },
};

/* Keybindings for Media play/pause/next/previous */
/* click can be ClkTagBar, ClkLtSymbol, ClkStatusText, ClkWinTitle, ClkClientWin, or ClkRootWin */
static Button buttons[] = {
	/* click                event mask      button          function        argument */
	{ ClkLtSymbol,          0,              Button1,        setlayout,      {0} },
	{ ClkLtSymbol,          0,              Button3,        setlayout,      {.v = &layouts[2]} },
	{ ClkWinTitle,          0,              Button2,        zoom,           {0} },
	{ ClkStatusText,        0,              Button2,        spawn,          {.v = termcmd } },
	{ ClkClientWin,         MODKEY,         Button1,        movemouse,      {0} },
	{ ClkClientWin,         MODKEY,         Button2,        togglefloating, {0} },
	{ ClkClientWin,         MODKEY,         Button3,        resizemouse,    {0} },
	{ ClkTagBar,            0,              Button1,        view,           {0} },
	{ ClkTagBar,            0,              Button3,        toggleview,     {0} },
	{ ClkTagBar,            MODKEY,         Button1,        tag,            {0} },
	{ ClkTagBar,            MODKEY,         Button3,        toggletag,      {0} },
};
