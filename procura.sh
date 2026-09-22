echo "=== A. MENUITEM é comando real ou só menção? ==="
grep -n '#command.*MENUITEM\|#xcommand.*MENUITEM\|#translate.*MENUITEM' ~/dev/hwgui/include/guilib.ch

echo ""
echo "=== B. Primeiras 20 linhas do guilib.ch ==="
head -20 ~/dev/hwgui/include/guilib.ch

echo ""
echo "=== C. Procura por erros típicos: #ifdef WIN32 não fechados ==="
grep -n '#ifdef\|#ifndef\|#if\b\|#else\|#endif' ~/dev/hwgui/include/guilib.ch | head -30

echo ""
echo "=== D. O que windows.ch tem no topo? ==="
head -20 ~/dev/hwgui/include/windows.ch
